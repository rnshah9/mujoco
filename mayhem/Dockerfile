FROM --platform=linux/amd64 ubuntu:22.04 as builder

RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y build-essential cmake git libx11-dev libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev freeglut3-dev clang

COPY . /repo
WORKDIR /repo/build
RUN cmake .. -DCMAKE_INSTALL_PREFIX=/install
RUN make -j8
RUN make install
RUN clang++ /repo/mayhem/fuzz_mju_halton.cpp -I/install/include -L/install/lib/ -lmujoco -fsanitize=address,fuzzer -o /fuzz

FROM ubuntu:22.04 as package
COPY --from=builder /install /install
COPY --from=builder /fuzz /fuzz_mju_halton
ENV LD_LIBRARY_PATH=/install/lib

