#include <iostream>
#include <emscripten/emscripten.h>
#include <unistd.h>
//emcc -std=c++11 worker.cpp -s EXPORTED_FUNCTIONS="['_one']" -o worker.js  -s BUILD_AS_WORKER=1
extern "C" {

void one(char* data, int size) {
    sleep (20);//Simulate work about 20 sec.
    emscripten_worker_respond(data, size);//Call main Thread. In this case call function onMessage in main.cpp
}
}