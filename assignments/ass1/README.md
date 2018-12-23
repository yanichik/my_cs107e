---
layout: page
title: 'Assignment 1: Implement a Larson Scanner'
permalink: /assignments/assign1/
released: true
toc: true
---

*Written by Pat Hanrahan*

**Due: Wednesday, Oct 10, 2018 at 11:30 AM**

[Glen A. Larson](http://en.wikipedia.org/wiki/Glen_A._Larson),
the man responsible for producing
the original
[Battlestar Galactica](http://en.wikipedia.org/wiki/Battlestar_Galactica)
and
[Knight Rider](http://en.wikipedia.org/wiki/Knight_Rider_%281982_TV_series%29)
television series,
often used simple lighting effects in his shows.
One famous example is a scanner
that consists of a set of red LEDs that scan back and forth.
The front of the Knight Rider car had a scanner.

![Knight Rider Car](images/knightrider.jpg)

Check out this short
[video tribute](https://www.youtube.com/watch?v=hDUoyeMLxqM)
to Glen Larson.
How many times does the scanner pattern appear?

Check out the [Larson Scanner Kit Demo](https://www.youtube.com/watch?v=yYawDGDsmjk) from evilmadscientist.com.

## Goals
When you're done with this assignment, you should

- understand ARM assembly language,

- feel fluent with the ARM cross-development tools,

- know how to use breadboards and use LEDs,

- and be able to program general-purpose input/output (GPIO) pins.

## Basic part: simple scan pattern

This assignment involves modifying the blink program showed in class.
`blink.s` is an ARM assembly language program that blinks a single LED.
To implement a scanner, you will need to control at least 4 LEDs.

### 1. Wire up your breadboard
The basic scanner should have a row of 4 LEDs. If you feel ambitious and want to make more interesting patterns, wire up 8 LEDs. Validate your breadboard wiring by testing that each LED lights up when powered.

### 2. Connect the LEDs to GPIO 20-23
The leftmost LED in your scanner should be connected to GPIO 20 of your Raspberry Pi, the second from the left to GPIO 21, and so on, such that the rightmost LED in your scanner is connected to GPIO 23 (or GPIO 27 if using 8 LEDs). Refer to the [Raspberry Pi pinout](https://pinout.xyz/) to map each GPIO to the physical pin so that you correctly wire up the connections.

### 3. Clone starter, test blink

To get the starter code, go to your assignments repository and pull the latest version of the
master branch:

```
$ cd cs107e_home/assignments
$ git checkout master
$ git pull
```

If you get an error message with your `git pull` command, contact the course
staff for help.

To start your work on this branch, you should create a new branch as we did in
assignment 0.

    $ git checkout assign1-basic

The version `larson.s` in the starter code is simply a copy of `blink.s` from
lab. 

Note that we have also included a file called `Makefile` in the starter code. This script
is similar to the `doit` scripts you saw in class&mdash;it will use the `as` and `objcopy` utilities
to compile your `larson.s` into a `larson.bin` file that you can install to the Pi. To execute
the Makefile, you should run `make` from the command line in the directory containing the Makefile, e.g.

```
$ make
$ rpi-install.py larson.bin
```

For now, don't worry about how `make` works. We'll go through Makefiles in-depth in the next lab.

If you build and test the starter program, it should blink the leftmost LED of your scanner on a correctly-wired breadboard.  You're now ready to write your scanner program!

### 4. Configure scanner GPIOs
The starter program is a copy of the `blink.s` you studied in lab1. This program configures the single pin GPIO 20 and enters an infinite loop to set and clear that pin. Carefully review this code and be sure you understand how it accomplishes its tasks. Ask questions if anything is unclear! Your job is to modify this program to instead blink the scanner sequence.  

A good first step is to extend the initialization code to configure all of the GPIOs your scanner uses, not just GPIO 20. Refer to section 6 of the [Broadcom ARM Peripheral](/readings/BCM2835-ARM-Peripherals.pdf) for the details on the GPIO registers.

Be sure to verify that your configuration code is correct. You can test an individual pin by changing the existing loop to blink GPIO 21 or GPIO 22 and so on instead of GPIO 20. Once you have verified that all pins are properly configured, you're now ready to tackle changing the loop body to blink the pins in the scanner sequence.
  
### 5. Generate scanner pattern
The loop will scan back and forth from the GPIO 20 LED to the GPIO 23 LED. Each iteration of the loop still turns on/off one GPIO, but instead of blinking the same GPIO each time, it will blink the next GPIO pin in sequence. If you invest a little bit of cleverness in how the loop advances from pin to pin, you can implement the entire scanner sequence with a fairly tight single loop.

Exactly one LED should be on at any given time, so it looks like the 
light is 'moving' between LEDs. Make sure you handle the left and right 
sides properly (that is, the leftmost and rightmost LED should be each 
on for the same amount of time that a middle LED would be on).

Writing clean, readable assembly code is a challenge. Commenting is essential!  Be sure to choose good label names and add named constants using `.equ` to aid readability. You should write the program without any function calls (because we haven't taught you how to create and call functions in assembly language yet). Although you cannot use functions, you can still strive for simplicity in your design. When you need the same/similar code, please don't resort to duplicating code via copy and paste, instead consider how to structure your code to enable unification and code reuse. A rule of thumb for style is that if your code is well-designed, it should take no additional code to extend it from 4 to 8 LEDs, ideally just changing a constant. If there is a lot of code duplication in your solution, that's a bad sign. We will be grading your code quality and hope to see your best work in what you submit!

Congratulations on completing your first step on the path to bare-metal mastery! Sit back and enjoy the show. Turn off the lights and impress your friends. 

Before moving on, you should be sure that you have committed and pushed a
working copy of your basic portion of this assignment.  Refer to the
instructions in the [assign0 writeup](/assignments/assign0/) if you have
trouble getting your files pushed to GitHub.

## Extensions

Each assignment is structured into a basic part and one or more proposed extensions. Completing the basic part is required. Doing solid work on the basic part puts you on track for earning a B grade. Adding in the optional extensions can boost your grade up into the A range. We encourage everyone to try out some of the extensions, they are a fun way to go further with the material and advance your understanding!

**(See the [assignment policy](/assignments/) page for more about our grade expectations.)**

The basic part of this assignment should not take too long once you
understand ARM assembly.

If you want to explore further, extend the program.
The extension is more challenging, and
may involve using additional ARM assembly instructions.

<!---
1 Program up 4 more patterns.
If you want ideas,
check out some of these
[patterns](https://www.youtube.com/watch?v=uUlkumlkryo#t=17).
-->

If you watch the Larson scanner carefully,
several LEDs are turned on at once.
The center one is at full brightness,
and the ones on the edge are dimmer.
How would you dim an LED?
Implement a scanner with LEDs dimmed
in a way that would please Glen Larson.

You should have a central, full-brightness light that scans just like
in the basic version of the assignment, but you should visibly dim the
neighbors of that central light as it moves. It should look similar to
the
[Larson Scanner Kit Demo](https://www.youtube.com/watch?v=yYawDGDsmjk).

Try to have at least three distinct levels of brightness.

If you choose to implement the extension, you should create a new branch
**after** you have committed a working copy of your basic

    $ git checkout -b assign1-extension

Now, you can commit and push your changes for the extension on this new branch.
Make sure you have committed and pushed a working copy of the basic assignment
(on the `assign1-basic` branch) before you start on the extension!

## Submit and automated check
Submit the finished version of your assignment by making a git "pull request"
from the `assign1-basic` branch to `master`, following steps given in the
[Assignment 0 writeup](/assignments/assign0/).  If you implemented the
extension, you should create a separate pull request for `assign1-extension`
into `master`.

The automated check here is more likely to fail than in assignment 0,
since there are more things that can go wrong. In this assignment, the
automated checker is verifying that:

- you have a Makefile (which we've included in the starter code, so
you should be fine if you keep that as is)
- you haven't checked larson.bin in (you should only be checking in
  your source code, and then we'll build larson.bin from it on our
  end)
- `make` runs successfully on the clean testing virtual machine
- `make` generates a `larson.bin` file

When we actually grade your submission, the human grader will assemble
the `larson.bin` file again, then test it on a physical Raspberry Pi
with the LEDs plugged in.

As stated on the [assignment policy](/assignments/) page, if you
submit an assignment solution that does not compile on CI, **we will
deduct 1 point from your basic grade**.

See the [automated checker guide](/guides/ci/) for more information
about the system, and details on how to see what went wrong.
