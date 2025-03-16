FROM ubuntu:24.04 AS base

RUN touch /var/mail/ubuntu && \
    chown ubuntu /var/mail/ubuntu && \
    userdel -r ubuntu

# Install basic utilities
ARG DEBIAN_FRONTEND=noninteractive
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
		bison \
        build-essential \
		curl \
		flex \
		gpg \
		lsb-release \
		nasm \
		ninja-build \
		software-properties-common \
        ssh-client \
		tar \
		unzip \
		wget \
		zip
# Setup git repository for apt
RUN apt-get purge -y --auto-remove git && \
    add-apt-repository ppa:git-core/ppa
# Setup kitware repository for apt
RUN KEY=/usr/share/keyrings/kitware-archive-keyring.gpg && \
	wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc 2>/dev/null |\
    	gpg --dearmor - |\
    	tee $KEY >/dev/null && \
	echo "deb [signed-by=$KEY] https://apt.kitware.com/ubuntu $(lsb_release -cs) main" |\
		tee /etc/apt/sources.list.d/kitware.list > /dev/null && \
	apt-get update && \
	rm $KEY && \
    apt-get install -y kitware-archive-keyring
# Use updated apt lists to install most recent versions of tools
RUN apt-get update && \
    apt-get install -y \
		clang \
		clang-format \
		cmake \
		gdb \
        git \
		libomp-dev \
		pkg-config \
		python3-setuptools

FROM base AS non-root
ARG USER_ID
ARG USER_NAME
ARG USER_GID
ARG USER_GROUP
RUN apt-get update && apt-get install sudo
RUN groupadd -g ${USER_GID} ${USER_GROUP} && \
    useradd ${USER_NAME} -u ${USER_ID} -g ${USER_GROUP} -G sudo -m -s /bin/bash && \
    echo "${USER_NAME}:${USER_NAME}" | chpasswd
USER ${USER_NAME}
RUN mkdir /home/${USER_NAME}/workspace
WORKDIR /home/${USER_NAME}/workspace

FROM base AS root
RUN echo "root:root" | chpasswd
USER root
RUN mkdir /root/workspace
WORKDIR /root/workspace
