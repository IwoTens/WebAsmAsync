# WebAsmAsync
Compile as:
    emcc main.cpp -o main.js -s EXPORTED_FUNCTIONS="['_async']" -s RESERVED_FUNCTION_POINTERS=2 -s USE_PTHREADS=1 -s PTHREAD_POOL_SIZE=2 -s ASYNCIFY=1 -s ASYNCIFY_FUNCTIONS="['_async']" -std=c++11 --bind
    emcc -std=c++11 worker.cpp -s EXPORTED_FUNCTIONS="['_one']" -o worker.js  -s BUILD_AS_WORKER=1
