#!/usr/bin/env python3

import random

samplecases = [
    'yurufuwa',
    'furugura',
    'gatimuti',
]
testcases = [
    'xuxuxuxa',
    'xuxuxuxu',
    'xuxuxixa',
    'xuxixuxa',
    'xixuxuxa',
    'xixixixa',
    'uyurufaw'
]

for i,str in enumerate(samplecases):
    with open('sample_{:02d}.in'.format(i), 'w') as fout:
        fout.write(str + '\n')

for i,str in enumerate(testcases):
    with open('input_{:02d}.in'.format(i), 'w') as fout:
        fout.write(str + '\n')
