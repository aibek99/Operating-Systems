#!/bin/bash
sudo fallocate -l 50M lofs.img
sudo losetup -f lofs.img
dir=`losetup -a | grep 'lofs.img' | awk '{print $1}'`
sudo mkfs.ext4 $dir
mkdir lofsdisk
sudo mount $dir ./lofsdisk
sudo mount -o loop .$dir ./lofsdisk
