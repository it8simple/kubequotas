FROM ubuntu:21.04
COPY memfill /usr/bin
ENTRYPOINT ["/usr/bin/memfill"]
