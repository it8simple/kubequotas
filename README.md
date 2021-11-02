# Kubernetes Basics (Quotas)

This repository contains the files used in the It Just Made Simple blog post about requests, limits and quotas in Kubernetes. It can be found [here](https://www.itjustmadesimple.com/2021/11/02/kubernetes-basics-part-12-requests-limits-and-resource-quotas/).

## Memfill

__Memfill__ is a C program used to simulate incremental memory allocations of a Linux process over time. It is similar to the *stress* command, and its behaviour can be modified by using command line parameters.

### <span id="parameters">Parameters</span>

- initial_delay: The amount of time in seconds between the start of the program and the beginning of the first memory allocation. Defaults to *0*.
- allocation_size: The size in bytes of each memory allocation. Defaults to *256\*1024\*1024*.
- num_realloc: The amount of reallocations after the first one. Defaults to *1*.
- delay_between_realloc: The amount of time in seconds to wait between allocations. Defaults to *30*.
- final_delay = The amount of time in seconds between the last allocation and the end of the program. Defaults to *30*.

All parameters are optional and positional, so in order to set, for example, *num_realloc*, *initial_delay* and *allocation_size* must be also set.

### How it works

1. When it's started, the program waits *initial_delay* seconds.
2. Performs the first memory allocation of *allocation_size* bytes and waits *delay_between_realloc* seconds.
3. Iterates *num_realloc* times, reallocating additional *allocation_size* bytes and waiting *delay_between_realloc* seconds.
4. Waits *final_delay* seconds before the process ends.

### Compile and run

To compile, on a Ubuntu/Debian distro execute:

`gcc memfill.c -o memfill`

To run with default values:

`./memfill`

If you want to pass parameters, refer to the [Parameters](#parameters) section.

### Cautions

*Memfill* was originally developed for demonstration purposes. Therefore, it's not suitable for "production" uses, at least in its current state. Of course, you can improve it if you need to.

### To-Do list

- Use flags to pass parameters
- Check parameters validity
- Add on-screen help

## Dockerfile

Use the provided Dockerfile to generate a Docker image with the program in it. First of all, compile the application and give execution permissions:

`chmod +x memfill`

Create the image with:

`docker build -t memfill .`
