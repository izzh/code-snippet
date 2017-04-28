#!/usr/bin/env python
# encoding: utf-8

import hashlib

'''
md5 file with filename(MD5)
'''
def MD5FileWithName(fileName, block_size=64*1024):
    with open(fileName) as f:
        md5 = hashlib.md5()
        while True:
            data = f.read(block_size)
            if not data:
                break
            md5.update(data)
        # retmd5 = base64.b64encode(md5.digest())
        return md5.hexdigest()

if __name__ == "__main__":
    md5 = MD5FileWithName("22.apk")
    print(md5)
