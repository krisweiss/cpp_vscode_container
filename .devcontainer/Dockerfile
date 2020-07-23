FROM debian:bullseye

# This Dockerfile's base image has a non-root user with sudo access. Use the "remoteUser"
# property in devcontainer.json to use it. On Linux, the container user's GID/UIDs
# will be updated to match your local UID/GID (when using the dockerFile property).
# See https://aka.ms/vscode-remote/containers/non-root-user for details.
ARG USERNAME=vscodes
ARG USER_UID=1000
ARG USER_GID=$USER_UID

# Configure apt and install packages
RUN apt-get update \
    && export DEBIAN_FRONTEND=noninteractive \
    #
    # Install C++ tools
    && apt-get -y install git gdb cmake catch2 \
        clang-10 clangd-10 clang-tidy-10 clang-format-10 llvm-10; \
        update-alternatives --install /usr/bin/clang clang /usr/bin/clang-10 100; \
        update-alternatives --install /usr/bin/cc cc /usr/bin/clang-10 100; \
        update-alternatives --install /usr/bin/clang++ clang++ /usr/bin/clang++-10 100; \
        update-alternatives --install /usr/bin/c++ c++ /usr/bin/clang++-10 100; \
        update-alternatives --install /usr/bin/clangd clangd /usr/bin/clangd-10 100; \
        update-alternatives --install /usr/bin/clang-tidy clang-tidy /usr/bin/clang-tidy-10 100; \
        update-alternatives --install /usr/bin/clang-format clang-format /usr/bin/clang-format-10 100 \
        
    #
    # [Optional] Update UID/GID if needed
    && if [ "$USER_GID" != "1000" ] || [ "$USER_UID" != "1000" ]; then \
        groupmod --gid $USER_GID $USERNAME \
        && usermod --uid $USER_UID --gid $USER_GID $USERNAME \
        && chown -R $USER_UID:$USER_GID /home/$USERNAME; \
    fi \
    #
    # Clean up
    && apt-get autoremove -y \
    && apt-get clean -y \
    && rm -rf /var/lib/apt/lists/*