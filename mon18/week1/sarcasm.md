# sArCaSm!

## Background

On the internet, there are usually 2 ways to convey sarcasm:

1. Using a `/s` at the end of your sentence ('I will drop out and become a prompt engineer and earn 500K a year! /s')
2. Writing your sentence in alternating casing ('i wIlL DrOp oUt aNd bEcOmE A PrOmPt eNgInEeR AnD EaRn 500K A YeAr!')

Dong is a computing student at UNSW. He spends his spare time getting into pointless arguments on Twitter. Dong recently finished COMP1511 and wishes to use his C programming skills to 'good use'.

## Task

Write a C program that:

1. Takes a string as a command line argument
2. Converts the letters to sarcastic casing (ignoring whatever casing the string already had)
3. Prints it out to terminal (`stdout`)

### Desired Usage

```sh
$ ./sarcasise 'hello world'
hElLo wOrLd
$ ./sarcasise 'HELLO WORLD'
hElLo wOrLd
$ ./sarcasise 'I will drop out and become a prompt engineer and earn 500K a year!11!!1'
i wIlL DrOp oUt aNd bEcOmE A PrOmPt eNgInEeR AnD EaRn 500K A YeAr!11!!1
```
