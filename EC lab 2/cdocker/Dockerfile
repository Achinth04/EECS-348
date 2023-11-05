# Set the base image to use
FROM gcc:latest
# Copy the C program into the container
COPY score.c .
# Compile the C program
RUN gcc -o score score.c
# Set the command to run when the container starts
CMD ["./score"]