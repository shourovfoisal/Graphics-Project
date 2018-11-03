
#ifdef __APPLE__
#include <GLUT/glut.h>      // For apple systems
#else
#include <GL/glut.h>        // For windows systems
#endif  // __APPLE__

#include <stdio.h> 
#include <math.h>

#define PI 3.14159265358

// Positional variables - amount of increase in position
float just_a_block_x = 0.0;
float just_a_block_y = 0.0;

float tank_x = 0.0;
float tank_y = 0.0;

float red_tank_x = 0.0;
float red_tank_y = 0.0;

float ship_x = 0.0;
float ship_y = 0.0;

float fighter_x = 0.0;
float fighter_y = 0.0;

float fighter2_x = 0.0;
float fighter2_y = 0.0;


void background() {
    
    // SKY
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, 0.0);     // TOP LEFT
    glVertex3f(1.0, 1.0, 0.0);      // TOP RIGHT
    glVertex3f(1.0, 0.0, 0.0);     // BOTTOM RIGHT
    glVertex3f(-1.0, 0.0, 0.0);    // BOTTOM LEFT
    glEnd();
    
    
    // Sea
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.8, 0.8);
    glVertex3f(-1.0, 0.0, 0.0);     // TOP LEFT
    glVertex3f(1.0, 0.0, 0.0);      // TOP RIGHT
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(1.0, -0.4, 0.0);     // BOTTOM RIGHT
    glVertex3f(-1.0, -0.4, 0.0);    // BOTTOM LEFT
    glEnd();
    
    
    // Field
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.95, 0.95);
    glVertex3f(-1.0, -0.4, 0.0);     // TOP LEFT
    glVertex3f(1.0, -0.4, 0.0);      // TOP RIGHT
    glColor3f(1.0, 0.871, 0.678);
    glVertex3f(1.0, -1.0, 0.0);     // BOTTOM RIGHT
    glVertex3f(-1.0, -1.0, 0.0);    // BOTTOM LEFT
    glEnd();
    
}

void sun() {
    
    // SUN
    
    int i;
	int triangleAmount = 50; //# of triangles used to draw circle
	
	float x = 0.0;
	float y = 0.7;
	float radius = 0.10;
	
	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;
	
	glLoadIdentity();
	//glTranslatef(0.0, 0.0, 0.8);
	glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0, 1.0, 0.0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) { 
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)), 
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
    
    // SUN
    
    // SUN RAYS
    
    // Top Line
    glLineWidth(2.5); 
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(0.0, 0.82, 0.0);
    glVertex3f(0.0, 0.94, 0.0);
    glEnd();
    
    // Bottom Line
    glLineWidth(2.5); 
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(0.0, 0.58, 0.0);
    glVertex3f(0.0, 0.46, 0.0);
    glEnd();
    
    // Left Line
    glLineWidth(2.5); 
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(-0.12, 0.7, 0.0);
    glVertex3f(-0.28, 0.7, 0.0);
    glEnd();
    
    // Right Line
    glLineWidth(2.5); 
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(0.12, 0.7, 0.0);
    glVertex3f(0.28, 0.7, 0.0);
    glEnd();
    
    
    // Top Left
    glLineWidth(2.5); 
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(-0.12, 0.8, 0.0);
    glVertex3f(-0.18, 0.86, 0.0);
    glEnd();
    
    // Top Right
    glLineWidth(2.5); 
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(0.12, 0.8, 0.0);
    glVertex3f(0.18, 0.86, 0.0);
    glEnd();
    
    // Bottom Left
    glLineWidth(2.5); 
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(-0.12, 0.6, 0.0);
    glVertex3f(-0.18, 0.54, 0.0);
    glEnd();
    
    // Bottom Right
    glLineWidth(2.5); 
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(0.12, 0.6, 0.0);
    glVertex3f(0.18, 0.54, 0.0);
    glEnd();
    
    // SUN RAYS
    
}


void tank(float x_move, float y_move) {
    
    // TANK
    
    // Tank Gun Barrel
    glLineWidth(5.0); 
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_LINES);
    glVertex3f(-0.70+x_move, -0.510+y_move, 0.0);
    glVertex3f(-0.86+x_move, -0.600+y_move, 0.0);
    glEnd();
    
    // Tank Top
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.5, 0.0);
    glVertex3f(-0.92+x_move, -0.57+y_move, 0.0);     // TOP LEFT
    glVertex3f(-0.84+x_move, -0.57+y_move, 0.0);      // TOP RIGHT
    glVertex3f(-0.82+x_move, -0.6+y_move, 0.0);     // BOTTOM RIGHT
    glVertex3f(-0.94+x_move, -0.6+y_move, 0.0);    // BOTTOM LEFT
    glEnd();
    
    // Tank Body
    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-1.00+x_move, -0.6+y_move, 0.0);     // TOP LEFT
    glVertex3f(-0.76+x_move, -0.6+y_move, 0.0);      // TOP RIGHT
    glVertex3f(-0.76+x_move, -0.65+y_move, 0.0);     // BOTTOM RIGHT
    glVertex3f(-1.00+x_move, -0.65+y_move, 0.0);    // BOTTOM LEFT
    glEnd();
    
    // Tank Chain
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-1.00+x_move, -0.65+y_move, 0.0);     // TOP LEFT
    glVertex3f(-0.76+x_move, -0.65+y_move, 0.0);      // TOP RIGHT
    glVertex3f(-0.78+x_move, -0.68+y_move, 0.0);     // BOTTOM RIGHT
    glVertex3f(-0.98+x_move, -0.68+y_move, 0.0);    // BOTTOM LEFT
    glEnd();
    
    // TANK
    
}

void red_tank(float x_move, float y_move) {
    
    // TANK
    
    // Tank Gun Barrel
    glLineWidth(5.0); 
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_LINES);
    glVertex3f(0.70+x_move, -0.510+y_move, 0.0);
    glVertex3f(0.86+x_move, -0.600+y_move, 0.0);
    glEnd();
    
    // Tank Top
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.84+x_move, -0.57+y_move, 0.0);     // TOP LEFT
    glVertex3f(0.92+x_move, -0.57+y_move, 0.0);      // TOP RIGHT
    glVertex3f(0.94+x_move, -0.6+y_move, 0.0);     // BOTTOM RIGHT
    glVertex3f(0.82+x_move, -0.6+y_move, 0.0);    // BOTTOM LEFT
    glEnd();
    
    // Tank Body
    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(0.76+x_move, -0.6+y_move, 0.0);     // TOP LEFT
    glVertex3f(1.00+x_move, -0.6+y_move, 0.0);      // TOP RIGHT
    glVertex3f(1.00+x_move, -0.65+y_move, 0.0);     // BOTTOM RIGHT
    glVertex3f(0.76+x_move, -0.65+y_move, 0.0);    // BOTTOM LEFT
    glEnd();
    
    // Tank Chain
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(0.76+x_move, -0.65+y_move, 0.0);     // TOP LEFT
    glVertex3f(1.00+x_move, -0.65+y_move, 0.0);      // TOP RIGHT
    glVertex3f(0.98+x_move, -0.68+y_move, 0.0);     // BOTTOM RIGHT
    glVertex3f(0.78+x_move, -0.68+y_move, 0.0);    // BOTTOM LEFT
    glEnd();
    
    // TANK
    
}


void ship(float x_move, float y_move) {
    
    // SHIP
    
    // Body
    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-0.20+x_move, -0.10+y_move, 0.0);     // TOP LEFT
    glVertex3f(0.20+x_move, -0.10+y_move, 0.0);      // TOP RIGHT
    glVertex3f(0.15+x_move, -0.18+y_move, 0.0);     // BOTTOM RIGHT
    glVertex3f(-0.15+x_move, -0.18+y_move, 0.0);    // BOTTOM LEFT
    glEnd();
    
    // Building
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.5, 0.0);
    glVertex3f(-0.15+x_move, -0.03+y_move, 0.0);     // TOP LEFT
    glVertex3f(-0.0+x_move, -0.03+y_move, 0.0);      // TOP RIGHT
    glVertex3f(-0.0+x_move, -0.1+y_move, 0.0);     // BOTTOM RIGHT
    glVertex3f(-0.15+x_move, -0.1+y_move, 0.0);    // BOTTOM LEFT
    glEnd();
    
    // Main Gun
    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-0.10+x_move, 0.01+y_move, 0.0);     // TOP LEFT
    glVertex3f(-0.06+x_move, 0.01+y_move, 0.0);      // TOP RIGHT
    glVertex3f(-0.04+x_move, -0.03+y_move, 0.0);     // BOTTOM RIGHT
    glVertex3f(-0.12+x_move, -0.03+y_move, 0.0);    // BOTTOM LEFT
    glEnd();
    
    // Main Gun Barrel
    glLineWidth(5.0); 
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_LINES);
    glVertex3f(-0.08+x_move, -0.01+y_move, 0.0);
    glVertex3f(-0.02+x_move, 0.06+y_move, 0.0);
    glEnd();
    
    
    // Missile Launch Pad
    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(0.08+x_move, -0.07+y_move, 0.0);     // TOP LEFT
    glVertex3f(0.15+x_move, -0.07+y_move, 0.0);      // TOP RIGHT
    glVertex3f(0.15+x_move, -0.10+y_move, 0.0);     // BOTTOM RIGHT
    glVertex3f(0.08+x_move, -0.10+y_move, 0.0);    // BOTTOM LEFT
    glEnd();
    
    
    // Missile (Left Stand - Back)
    glLineWidth(5.0); 
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    glVertex3f(0.07+x_move, -0.03+y_move, 0.0);
    glVertex3f(0.12+x_move, 0.02+y_move, 0.0);
    glEnd();
    
    // Missile Launch Stand (Left)
    glLineWidth(5.0); 
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_LINES);
    glVertex3f(0.10+x_move, -0.07+y_move, 0.0);
    glVertex3f(0.10+x_move, 0.0+y_move, 0.0);
    glEnd();
    
    // Missile (Left Stand - Front)
    glLineWidth(5.0); 
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    glVertex3f(0.07+x_move, -0.05+y_move, 0.0);
    glVertex3f(0.12+x_move, 0.00+y_move, 0.0);
    glEnd();
    
    
    
    // Missile (Right Stand - Back)
    glLineWidth(5.0); 
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_LINES);
    glVertex3f(0.10+x_move, -0.03+y_move, 0.0);
    glVertex3f(0.15+x_move, 0.02+y_move, 0.0);
    glEnd();
    
    // Missile Launch Stand (Right)
    glLineWidth(5.0); 
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_LINES);
    glVertex3f(0.13+x_move, -0.07+y_move, 0.0);
    glVertex3f(0.13+x_move, 0.00+y_move, 0.0);
    glEnd();
    
    // Missile (Right Stand - Front)
    glLineWidth(5.0); 
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_LINES);
    glVertex3f(0.10+x_move, -0.05+y_move, 0.0);
    glVertex3f(0.15+x_move, 0.00+y_move, 0.0);
    glEnd();
    
    
    // SHIP
    
}


void fighter(float x_move, float y_move) {
    
    // Tail
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.93+x_move, 0.75+y_move, 0.0);     // TOP LEFT
    glVertex3f(1.0+x_move, 0.78+y_move, 0.0);      // TOP RIGHT
    glVertex3f(1.0+x_move, 0.72+y_move, 0.0);     // BOTTOM RIGHT
    glVertex3f(0.93+x_move, 0.75+y_move, 0.0);    // BOTTOM LEFT
    glEnd();
    
    // Body
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.85+x_move, 0.78+y_move, 0.0);     // TOP LEFT
    glVertex3f(0.94+x_move, 0.77+y_move, 0.0);      // TOP RIGHT
    glVertex3f(0.94+x_move, 0.73+y_move, 0.0);     // BOTTOM RIGHT
    glVertex3f(0.85+x_move, 0.72+y_move, 0.0);    // BOTTOM LEFT
    glEnd();
    
    // Wing
    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(0.92+x_move, 0.81+y_move, 0.0);     // TOP LEFT
    glVertex3f(0.95+x_move, 0.81+y_move, 0.0);      // TOP RIGHT
    glVertex3f(0.92+x_move, 0.75+y_move, 0.0);     // BOTTOM RIGHT
    glVertex3f(0.87+x_move, 0.75+y_move, 0.0);    // BOTTOM LEFT
    glEnd();
    
    // Motor
    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(0.83+x_move, 0.77+y_move, 0.0);     // TOP LEFT
    glVertex3f(0.85+x_move, 0.78+y_move, 0.0);      // TOP RIGHT
    glVertex3f(0.85+x_move, 0.72+y_move, 0.0);     // BOTTOM RIGHT
    glVertex3f(0.83+x_move, 0.73+y_move, 0.0);    // BOTTOM LEFT
    glEnd();
    
    
    // Propeller
    glLineWidth(2.0); 
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_LINES);
    glVertex3f(0.82+x_move, 0.79+y_move, 0.0);
    glVertex3f(0.82+x_move, 0.71+y_move, 0.0);
    glEnd();
    
    // Propeller Nut
    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(0.81+x_move, 0.76+y_move, 0.0);     // TOP LEFT
    glVertex3f(0.82+x_move, 0.76+y_move, 0.0);      // TOP RIGHT
    glVertex3f(0.82+x_move, 0.74+y_move, 0.0);     // BOTTOM RIGHT
    glVertex3f(0.81+x_move, 0.74+y_move, 0.0);    // BOTTOM LEFT
    glEnd();
    
}


void blinking_box(float x_move, float y_move) {
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.00+x_move, 0.00+y_move, 0.0);     // TOP LEFT
    glVertex3f(0.03+x_move, 0.00+y_move, 0.0);      // TOP RIGHT
    glVertex3f(0.03+x_move, 0.03+y_move, 0.0);     // BOTTOM RIGHT
    glVertex3f(0.00+x_move, 0.03+y_move, 0.0);    // BOTTOM LEFT
    glEnd();
}

void bomb(float x_move, float y_move) {
    
    // Bomb Tail
    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-0.01+x_move, 0.02+y_move, 0.0);     // TOP LEFT
    glVertex3f(0.04+x_move, 0.02+y_move, 0.0);      // TOP RIGHT
    glVertex3f(0.04+x_move, 0.00+y_move, 0.0);     // BOTTOM RIGHT
    glVertex3f(-0.01+x_move, 0.00+y_move, 0.0);    // BOTTOM LEFT
    glEnd();
    
    // Bomb body
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.00+x_move, 0.00+y_move, 0.0);     // TOP LEFT
    glVertex3f(0.03+x_move, 0.00+y_move, 0.0);      // TOP RIGHT
    glVertex3f(0.03+x_move, -0.08+y_move, 0.0);     // BOTTOM RIGHT
    glVertex3f(0.00+x_move, -0.08+y_move, 0.0);    // BOTTOM LEFT
    glEnd();
    
    // Bomb Head
    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-0.01+x_move, -0.08+y_move, 0.0);     // TOP LEFT
    glVertex3f(0.04+x_move, -0.08+y_move, 0.0);      // TOP RIGHT
    glVertex3f(0.015+x_move, -0.10+y_move, 0.0);     // BOTTOM RIGHT
    glVertex3f(0.015+x_move, -0.10+y_move, 0.0);    // BOTTOM LEFT
    glEnd();
    
}


void red_flag(float x_move, float y_move) {
    
    // Flag Body
    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(0.00+x_move, 0.08+y_move, 0.0);     // TOP LEFT
    glVertex3f(0.01+x_move, 0.08+y_move, 0.0);      // TOP RIGHT
    glVertex3f(0.01+x_move, -0.08+y_move, 0.0);     // BOTTOM RIGHT
    glVertex3f(0.00+x_move, -0.08+y_move, 0.0);    // BOTTOM LEFT
    glEnd();

    // Flag Top
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.00+x_move, 0.09+y_move, 0.0);     // TOP LEFT
    glVertex3f(0.05+x_move, 0.07+y_move, 0.0);      // TOP RIGHT
    glVertex3f(0.05+x_move, 0.07+y_move, 0.0);     // BOTTOM RIGHT
    glVertex3f(0.00+x_move, 0.05+y_move, 0.0);    // BOTTOM LEFT
    glEnd();

    // Flag Bottom
    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-0.02+x_move, -0.08+y_move, 0.0);     // TOP LEFT
    glVertex3f(0.03+x_move, -0.08+y_move, 0.0);      // TOP RIGHT
    glVertex3f(0.03+x_move, -0.10+y_move, 0.0);     // BOTTOM RIGHT
    glVertex3f(-0.02+x_move, -0.10+y_move, 0.0);    // BOTTOM LEFT
    glEnd();

}



float counter = 0.0;
float delta_counter = 0.001;

int blink_counter = 0;

float bomb_drop_counter = 0.0;
float bomb_drop_counter2 = 0.0;


void display() {
    
    glClear( GL_COLOR_BUFFER_BIT);  

    
    
    /*-------------------
        New Coding
    -------------------*/
    
    
    // Load the background and the sun
    background();
    sun();
    
    // Move the tank to the right by 0.40 units
    if(counter<=0.40) {
        counter+=delta_counter;
        tank_x=counter;
        
        ship(0.0,0.0);      // Make the ship appear
    }
    if(1.35-bomb_drop_counter2>=0.0)        // The tanks stay on the screen until the bomb reaches their middle place
    {
        tank(tank_x,tank_y);
        tank(tank_x,tank_y-0.20);
    }
    
    // Move the ship to the left by 0.20 units
    if(counter>0.40) {
        if(counter<=0.60) {
            counter+=delta_counter;
            ship_x-=delta_counter;
        }
        if(0.72-bomb_drop_counter>=0.0)     // The ship remains on the screen until the bomb reaches it
            ship(ship_x,ship_y);
    }
    
    // Move the fighter to the left - off the screen (2.20 units. 2 for the viewport width, 0.20 for fighter length)
    if(counter>0.60) {
        if(counter<=2.80) {     // By 2.80 units, I alotted (2.80-0.60) = 2.20 units for the second fighter and 2.00 units for the first one because it launched 0.20 seconds earlier than the second
            counter+=delta_counter;
            fighter_x-=delta_counter;
        }
        fighter(fighter_x,fighter_y);
    }
    
    // Second fighter
    fighter2_y = -0.20;
    if(counter>0.80) {     // Move it from 0.20 units behind the first one
        if(counter<=2.80) {
            fighter2_x-=delta_counter;
        }
        fighter(fighter2_x,fighter2_y);
    }
    
    
    
    // After the tank and ship stops moving, the blink boxes appear
    blink_counter++;
    if(blink_counter==20)
        blink_counter = 0;
    else if(blink_counter>=0&&blink_counter<=10)
    {
        
        if(tank_x>0.40 && 1.35-bomb_drop_counter2>=0.0)     // These two blinking square remain on the screen until the bomb reaches the middle of the two tanks
        {
            blinking_box(-0.30, -0.51);
            blinking_box(-0.30, -0.71);
        }
        if(ship_x<-0.20 && 0.72-bomb_drop_counter>=0.0)     // This blinking square remains on the screen until the bomb reaches the ship
        {
            blinking_box(-0.22, 0.06);
        }
    }
    
    
    // Drop the bombs when the fighter reaches over the ship
    
    if(fighter_x<=-1.14)
    {
        bomb_drop_counter+=(delta_counter*2);
        if(0.72-bomb_drop_counter>=0.0)     // 0.72 is the distance between the y-coordinates of the bottom of fighter body and top of tank body
        {
            bomb(-0.25, 0.72-bomb_drop_counter);        // -0.25 is the x-coordinate of the middle of the ship body 
        }
    }
    
    if(fighter_x<=-1.37)        // 1.37 is the distance between x-coordinate of fighter body and tank body. The bomb may appear once the fighter crosses this much distance
    {
        bomb_drop_counter2+=(delta_counter*2);
        if(1.35-bomb_drop_counter2>=0.0)        // 1.35 is the roughly calculated distance between the y-coordinates of the bottom of the fighter body and the middle of two tanks
        {
            bomb(-0.48, 0.72-bomb_drop_counter2);
        }
    }
    
    
    
    // Red Victory - Bringing in the red tank
    
    if(counter>2.80) {
        if(counter<=3.10) {
            counter+=delta_counter;
            red_tank_x-=delta_counter;
        }
        red_tank(red_tank_x, 0.20);
        red_tank(red_tank_x-0.20, 0.0);
        red_tank(red_tank_x, -0.20);
    }
    
    
    // After red tanks arrive, bring in the red flag
    
    if(counter>3.10)
        red_flag(0.0, -0.60);
    
    
    /*-------------------
        New Coding
    -------------------*/
    
    glutSwapBuffers();
    
}

void reshape( int w , int h ) {
    glViewport( 0 , 0 , w , h );
}

void initOpenGL() {
    glClearColor( 0.0 , 0.0 , 1.0 , 1.0 );
}

int main( int argc, char **argv) {
    
    glutInit( &argc , argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA );
    glutInitWindowSize( 900 , 900 );
    glutInitWindowPosition( 100 , 100 );
    glutCreateWindow ( "Emon animation" );
    
    initOpenGL();
    
    glutDisplayFunc( display );
    glutIdleFunc( display );
    glutReshapeFunc( reshape );
    glutMainLoop();
    
    return 0;
}
