FROM ubuntu:21.10
ARG DEBIAN_FRONTEND=noninteractive

COPY ./src /app
WORKDIR /app
RUN mkdir -p build
WORKDIR /app/build

RUN apt-get update -y
RUN apt-get install libtbb-dev -y
RUN apt-get install build-essential -y
RUN apt-get install git -y
RUN apt-get install cmake -y
RUN apt-get upgrade -y

RUN apt-get install lua5.3 -y
RUN apt-get install liblua5.3-dev -y
RUN apt-get install lua-socket -y
RUN git clone https://github.com/lunarmodules/luasocket
WORKDIR /app/build/luasocket/src
RUN make
RUN mv * /usr/share/lua/5.3

WORKDIR /app/build
RUN apt-get install g++-10 -y
RUN apt-get install gcc-10 -y
RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-10 10
RUN update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-10 10

RUN cmake -DCMAKE_BUILD_TYPE=Release ..
RUN make
EXPOSE 1337
CMD ["./EvoFramework"]