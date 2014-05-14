process.chdir('./node_modules/gmat-console-node/gmat/');
var addon = require('gmat-console-node');
//console.log(addon.RunGmat("--help"));

//LD_LIBRARY_PATH=`pwd`/node_modules/gmat-console-node/lib/:$LD_LIBRARY_PATH node GmatConsoleNodeTest.js

//console.log(process.cwd());
//process.setuid();
//process.setgid();
console.log(addon.RunGmat("./samples/Ex_HohmannTransfer.script"));

/*
var args = ['/some/path','executable','args'];
process.execArgv(args);
*/
