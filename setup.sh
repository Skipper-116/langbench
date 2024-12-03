#!/bin/bash

# Function to install packages using Homebrew
install_with_brew() {
    brew install "$1"
}

# Function to install packages using apt
install_with_apt() {
    sudo apt-get update
    sudo apt-get install -y "$1"
}

# Detect the operating system
if [[ "$OSTYPE" == "darwin"* ]]; then
    PACKAGE_MANAGER="brew"
elif [[ "$OSTYPE" == "linux-gnu"* ]]; then
    PACKAGE_MANAGER="apt"
else
    echo "Unsupported OS type: $OSTYPE"
    exit 1
fi

# Install C++ compiler (Apple clang version 16.0.0 or compatible)
if [[ "$PACKAGE_MANAGER" == "brew" ]]; then
    xcode-select --install
else
    install_with_apt clang
fi

# Install .NET 9.0.100
if [[ "$PACKAGE_MANAGER" == "brew" ]]; then
    brew install --cask dotnet-sdk
else
    wget https://dotnet.microsoft.com/download/dotnet/thank-you/sdk-9.0.100-linux-x64-binaries
    sudo tar -xvf dotnet-sdk-9.0.100-linux-x64.tar.gz -C /usr/local/share/dotnet
    sudo ln -s /usr/local/share/dotnet/dotnet /usr/bin/dotnet
fi

# Install OpenJDK 21.0.3
if [[ "$PACKAGE_MANAGER" == "brew" ]]; then
    install_with_brew openjdk@21
else
    install_with_apt openjdk-21-jdk
fi

# Install Ruby 3.2.0
if [[ "$PACKAGE_MANAGER" == "brew" ]]; then
    install_with_brew ruby@3.2
else
    sudo apt-add-repository ppa:brightbox/ruby-ng
    sudo apt-get update
    install_with_apt ruby3.2
fi

# Install Python 3.12.7
if [[ "$PACKAGE_MANAGER" == "brew" ]]; then
    install_with_brew python@3.12
else
    sudo add-apt-repository ppa:deadsnakes/ppa
    sudo apt-get update
    install_with_apt python3.12
fi

# Install Node.js v20.15.1
if [[ "$PACKAGE_MANAGER" == "brew" ]]; then
    install_with_brew node@20
else
    curl -fsSL https://deb.nodesource.com/setup_20.x | sudo -E bash -
    install_with_apt nodejs
fi

# Install PHP 8.3.14
if [[ "$PACKAGE_MANAGER" == "brew" ]]; then
    install_with_brew php@8.3
else
    sudo add-apt-repository ppa:ondrej/php
    sudo apt-get update
    install_with_apt php8.3
fi

# Install Go go1.23.3
if [[ "$PACKAGE_MANAGER" == "brew" ]]; then
    install_with_brew go@1.23
else
    wget https://golang.org/dl/go1.23.3.linux-amd64.tar.gz
    sudo tar -C /usr/local -xzf go1.23.3.linux-amd64.tar.gz
    export PATH=$PATH:/usr/local/go/bin
fi

# Install Rust rustc 1.83.0 and cargo 1.83.0
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh -s -- -y
source $HOME/.cargo/env
rustup install 1.83.0
rustup default 1.83.0

# Install Dart SDK version: 3.4.3
if [[ "$PACKAGE_MANAGER" == "brew" ]]; then
    brew tap dart-lang/dart
    install_with_brew dart
else
    sudo apt-get update
    sudo apt-get install apt-transport-https
    wget -qO- https://dl-ssl.google.com/linux/linux_signing_key.pub | sudo apt-key add -
    sudo sh -c 'wget -qO- https://storage.googleapis.com/download.dartlang.org/linux/debian/dart_stable.list > /etc/apt/sources.list.d/dart_stable.list'
    sudo apt-get update
    install_with_apt dart
fi

echo "All specified versions have been installed."