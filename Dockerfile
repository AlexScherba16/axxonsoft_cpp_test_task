FROM gcc:latest as build

RUN cd /var/cache/debconf && \
    rm *.dat && \
    apt-get update && \
    apt-get upgrade -y && \
    apt-get install -y \
      build-essential libboost-dev libboost-thread-dev libboost-program-options-dev libboost-filesystem-dev\
      libgtest-dev \
      cmake

# copy project directory to container and set as root point
COPY . /opt/axxonsoft
WORKDIR /opt/axxonsoft

# update project submodules
# build project and run tests
RUN git submodule init && git submodule update && \
    mkdir build && cd build && \
    cmake .. && make && make test


# runner image
FROM ubuntu:latest

# add custom user =)
RUN groupadd -r sample && useradd -r -g sample sample
USER sample

# set application directory
WORKDIR /opt/axxonsoft

# copy binary file to application directory
COPY --from=build /opt/axxonsoft/build/linecounter .

# launch application
ENTRYPOINT ["./linecounter", "$input"]
