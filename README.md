# Hash Table investigation

## Introduction

This project is dedicated to investigating the Hash Table data structure.

## Objectives

The goals of this project are:

0. To implement a simple Hash Table using cache-friendly doubly linked list for handling collisions.

1. To test and compare different hash functions under certain conditions and choose the best one.

2. To determine hotspots, analyze them and optimize using:

    * Inline assembly
    * Intrinsics
    * Seperate assembly file

# Part 1. Hash function comparison

Let's firstly mark down all of the hash functions:

1. Zero hash
2. First letter ASCII hash
3. Word length hash
4. ASCII sum hash
5. ASCII sum divided by length hash
6. ROR hash
7. ROL hash
8. PNV hash

> Further on you will see histograms with collision distributions  

### Zero hash

This hash always returns 0, so it's obvious that all of the elements will be stored in 1st cell.

![](histograms/Zero%20hash.png)

It's not so great, because the time to get the last element depends on the amount of values we insert, which is not what we are looking for.

Max. amount of collisions: $\approx$ **29000 words**

### First letter ASCII hash

The text I use (Shakespeare) as data to explore contains only lower case words, from this we can conclude that the words are distributed in cells numerated from 97 to 122.

![](histograms/First%20char%20hash.png)

Better result, but still not so good.

Max. amount of collisions: $\approx$ **3500 words**

### Word length hash

The situation here is quite similair. 

![](histograms/String%20length%20hash.png)

