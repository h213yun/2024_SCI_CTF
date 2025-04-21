#!/bin/bash
NAME="cryptogenius-container"

sudo docker kill $NAME
sudo docker rm $NAME
sudo docker build --tag $NAME:1.0 ./

PORT="-p 1231:8080"
OPTION="-idt --privileged"

DEV_OPTION="--cap-add=SYS_PTRACE --security-opt seccomp=unconfined"

sudo docker run $OPTION $PORT --name $NAME $NAME:1.0
sudo docker attach $NAME

