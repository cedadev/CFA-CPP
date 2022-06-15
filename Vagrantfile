# -*- mode: ruby -*-
# vi: set ft=ruby :

# Vagrant configuration
Vagrant.configure(2) do |config|
  # Rocky 8 base box
  config.vm.box = "generic/rocky8"
  config.vm.box_version = "4.0.2"

  config.ssh.keys_only = "False"

  config.vm.network "private_network", ip: "192.168.51.9"

  synced_user = "vagrant"
  synced_group = "vagrant"

  config.vm.synced_folder "/Users/dhk63261/Coding/CFA-C", "/Coding/CFA-C",  owner: synced_user, group: synced_group
  config.vm.synced_folder "/Users/dhk63261/Coding/CFA-CPP", "/Coding/CFA-CPP",  owner: synced_user, group: synced_group
  config.vm.provision :shell, inline: <<SHELL
set -x

mkdir -p /root/.ssh
cp ~vagrant/.ssh/authorized_keys /root/.ssh

SHELL

$COMMANDS = <<-'BLOCK'
dnf config-manager --set-enabled powertools
dnf install epel-release
dnf install gcc -y
dnf install netcdf -y
dnf install netcdf-devel -y
dnf install netcdf-cpp
dnf install valgrind -y
BLOCK

config.vm.provision "shell", inline: $COMMANDS
end
