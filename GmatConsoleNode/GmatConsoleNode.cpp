#include <node.h>
#include <iostream>
#include <string.h>
#include <sstream>
#include <v8.h>

using namespace v8;

int mainGmat(int argc, char *argv[]);

Handle<Value> RunGmat(const Arguments& args) {
  HandleScope scope;

  /*if (args.Length() < 2) {
     ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
     return scope.Close(Undefined());
   }*/

   /*if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
     ThrowException(Exception::TypeError(String::New("Wrong arguments")));
     return scope.Close(Undefined());
   }*/

   /*Local<Number> num = Number::New(args[0]->NumberValue() +
       args[1]->NumberValue());
   return scope.Close(num);*/

  int argc = args.Length() + 1; //first arg is always the program name itself
  char* argv[argc];
  argv[0] = "GmatConsoleNode";  //program name

  for(int i=1;i<argc;++i)
  {
    if (args[i-1]->IsString())
    {
      String::Utf8Value vs(args[i-1]);
      std::string ss(*vs);
      argv[i] = new char[ss.length()+1];
      strncpy(argv[i],ss.c_str(),ss.length());
      //std::cout << "Adding " << ss << ", " << argv[i] << ", " <<  ss.length() << ", "<<  sizeof(argv[i]) << ", " << strlen(argv[i]) << std::endl;
      argv[i][ss.length()] = 0;
    }
    else
    {
      ThrowException(Exception::TypeError(String::New("Argument is not a string")));
      return scope.Close(Undefined());
    }
  }

  std::stringstream outBuff, errBuff;
  std::streambuf * oldOut = std::cout.rdbuf(outBuff.rdbuf());
  std::streambuf * oldErr = std::cerr.rdbuf(errBuff.rdbuf());
  mainGmat(argc,argv);
  std::cout.rdbuf(oldOut); //reassign old ones back, will crash otherwise on close
  std::cerr.rdbuf(oldErr);

  //std::string err = errBuff.str();

  return scope.Close(String::New(outBuff.str().c_str()));
}

void init(Handle<Object> exports) {
  exports->Set(String::NewSymbol("RunGmat"),
        FunctionTemplate::New(RunGmat)->GetFunction());
}

NODE_MODULE(GmatConsoleNode, init)
