#include <stdio.h>

#define NUM_PARTICLES 1

// Two dimensional vector
typedef struct{
    float x;
    float y;
} Vector2;

// Partile Structure
typedef struct{
    Vector2 position;
    Vector2 velocity;
    float mass;
} Particle;

Particle particles[NUM_PARTICLES];

//Print each particle position
void PrintParticles(){
    for(int i=0; i<NUM_PARTICLES; ++i){
        printf("particle [%i], position: (%.2f, %.2f)\n",i,particles[i].position.x, particles[i].position.y);
    }
}

//Initialize particles with position 0, velocity 0 and mass 1 kilogram
void InitializeParticles(){
    for(int i=0; i<NUM_PARTICLES; ++i){
        particles[i].position = (Vector2){0, 0};
        particles[i].velocity = (Vector2){0, 0};
        particles[i].mass = 1;
    }
}

// Apply gravitational acceleration ~9.81 m/s^2
Vector2 ApplyForce(Particle particle){
    return (Vector2){0, particle.mass * (-9.81)};  // {director, magnitute} of motion
}

void RunSimulation(){
    float totalSimulationTime = 10;
    float currentTime = 0;
    float dt = 1; // Each simulation will take 1 second.

    InitializeParticles();

    while(currentTime < totalSimulationTime){

        for(int i=0; i<NUM_PARTICLES; ++i){
            Particle particle = particles[i];
            Vector2 force = ApplyForce(particle); // Get force magnitude

            // F = m * a, m = F / a, a = F / m
            // F = force, m = mass, a = accelaration

            Vector2 accelaration = (Vector2){force.x / particle.mass, force.y / particle.mass };
            particle.velocity.x += accelaration.x * dt;
            particle.velocity.y += accelaration.y * dt;
            particle.position.x += particle.velocity.x * dt;
            particle.position.y += particle.velocity.y * dt;

            particles[i] = particle;
        }
        PrintParticles(); 
        currentTime += dt;
    }
}

void main(){
    RunSimulation();
}



