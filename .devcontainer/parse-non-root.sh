#!/bin/sh

# change pwd to directory, where this script is stored
: ${curdir:="$(dirname -- $(readlink -f -- "$0"))"}
cd $curdir

# parse IDs to non-root target of Dockerfile
sed --in-place \
    -e"s/^ARG USER_ID[[:alnum:]-]*/ARG USER_ID=$(id -u)/g" \
    -e"s/^ARG USER_NAME[[:alnum:]-]*/ARG USER_NAME=$(id -un)/g" \
    -e"s/^ARG USER_GID[[:alnum:]-]*/ARG USER_GID=$(id -g)/g" \
    -e"s/^ARG USER_GROUP[[:alnum:]-]*/ARG USER_GROUP=$(id -gn)/g" \
    Dockerfile
