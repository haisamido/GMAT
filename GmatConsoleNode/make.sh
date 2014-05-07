#!/bin/sh

node-gyp clean configure
cp lib* build/
node-gyp build
cp build/Release/GmatConsoleNode.node node_modules/gmat-console-node/bin/
cp build/lib*.so node_modules/gmat-console-node/lib/