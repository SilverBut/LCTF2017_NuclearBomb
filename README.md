# LCTF 2017: Nuclear Bomb

The name is "nuclear bomb", because it is designed as a CUDA-acclelerated program on Nvidia CUDA cards.

Basically, the program will use input to get a long random cipher, do some bit operations and subititles using GPU, and compare with preset table.

This is really easy, because only a first few bytes is used. And once you have got the first rand it get, you can get the original seed out, which can be concatenated into a long flag.

See `ctf_output/readme.txt`(in chinese) for more info.

This contest might be the last time for me, to write a challenge for CTF games. Thanks for XDSEC, and thanks for all my friends.

Happy hacking!

* * *

## Legal Statement

IDA, ATMEL, AVR and all other trademarks cited herein are the property of their respective owners.

Copyright of this repo is belonging to the original author of those code.

Unless otherwise stated, you are requested to follow GPLv3 to use code in this repo.

The following related parts are NOT allowed to use this code, unless a statement is signed and published by the author:

* Humensec (http://www.humensec.com)
* Network Behaviour Research Center (NBRC) in Xidian University (http://nbrc.xidian.edu.cn)
* School of Cyber Engineering of Xidian University (http://ce.xidian.edu.cn)
* Leaders, researchers, students and any other people or entity sharing common benefits with entities above

According to the relevant laws, including the *Cybersecurity Law of the People's Republic of China*, the author and other related entities will resort to legal measures if you are not complying this license.
