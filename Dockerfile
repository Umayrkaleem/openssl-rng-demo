# Use official Ubuntu as the base image
FROM ubuntu:22.04

# Install required packages
RUN apt-get update && \
    apt-get install -y build-essential libssl-dev make && \
    apt-get clean

# Set working directory inside the container
WORKDIR /app

# Copy the project files
COPY . .

# Build the project
RUN make PLATFORM=linux

# Default command runs the program
CMD ["./bin/random_sort"]