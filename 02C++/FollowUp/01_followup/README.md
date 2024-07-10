make -> manual excutables 
cmake -> instructions -> makefile(targets) -> excutable

//cmake -> readme

Alexa ALSA lib pcm problems

sudo apt-get install jackd2

sudo sysctl -w kernel.shmmax=2147483648
sudo sysctl -w kernel.shmall=2097152

jack_control start

try for jack


/etc/asound.conf

pcm.!default {
    type hw
    card 0
}

ctl.!default {
    type hw
    card 0
}



~/.asoundrc

pcm.dmixed {
    type dmix
    ipc_key 1024
    slave {
        pcm "hw:0,0"
        period_time 0
        period_size 1024
        buffer_size 4096
        rate 44100
    }
    bindings {
        0 0
        1 1
    }
}


sudo alsa force-reload


