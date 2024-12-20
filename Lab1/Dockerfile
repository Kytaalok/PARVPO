# Use base Alpine image
FROM alpine:latest

# Install necessary packages: g++, git
RUN apk update && apk add --no-cache g++ git

# Set working directory inside the container
WORKDIR /app

# Clone the repository
RUN git clone https://github.com/Kytaalok/PARVPO.git .

# List contents to verify cloning
RUN ls -la /app
RUN ls -la /app/Lab1

# Change to Lab1 directory
WORKDIR /app/Lab1

# Compile the program
RUN g++ benchmark.cpp -o benchmark -fopenmp

# Execute the program when the container starts
CMD ["./benchmark"]
