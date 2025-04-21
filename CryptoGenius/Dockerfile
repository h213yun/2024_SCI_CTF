# Use the official Ubuntu 20.04 base image
FROM ubuntu:20.04

# Update package lists and install necessary tools
RUN apt-get update \
    && apt-get install -y xinetd netcat gcc-multilib vim \
    && useradd -d /home/cryptoGenius cryptoGenius -s /bin/bash \
    && mkdir /home/cryptoGenius \
    && chown -R root:cryptoGenius /home/cryptoGenius \
    && chmod 750 /home/cryptoGenius

# Set the working directory
WORKDIR /home/cryptoGenius

# Copy the source code and compile it
COPY cryptoGenius.c /home/cryptoGenius/
RUN gcc -o cryptoGenius cryptoGenius.c

# Copy the challenge settings
COPY settings/chall.xinetd /etc/xinetd.d/chall
COPY settings/start.sh /start.sh
RUN chmod +x /start.sh

# Expose the port specified in chall.xinetd
EXPOSE 8080

# Set the entry point to start.sh
CMD ["/start.sh"]
