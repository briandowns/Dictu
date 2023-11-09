## Camus Docker

### Building the Docker image

Make sure you have Docker installed on your system. Refer to [Docker installation](https://docs.docker.com/engine/install/). 

To build the Docker image of Camus, clone the repository and change directory into `Camus`. 

Run the following command from the **root of the project** i.e, the `Camus` folder by default. 

To build the *Alpine* version of Camus - 

```bash
$ docker build -t camus:alpine -f Docker/CamusAlpineDockerfile . 
``` 

To build the *Ubuntu* version of Camus -

```bash 
$ docker build -t camus:ubuntu -f Docker/CamusUbuntuDockerfile . 
``` 

To start a REPL from this image, run - (Replace the tag with the appropriate version, i.e, alpine or ubuntu)

```bash 
$ docker run -it camus:ubuntu 
```

> The image built can be used in other docker images as a base image for running camus files. Make sure you have the image built locally.

```Dockerfile 
FROM camus:ubuntu 
COPY example.du . 
RUN camus example.du
```
