#include  "FPToolkit.c"

int main(){
  printf("Input integer n: ");
  int n;
  scanf("%d", &n);
  printf("Choose the center point and the radius of the upper ellipse.\n");
  
  int width = 600;
  int height = 600;
  G_init_graphics(width,height);

   // choose points
  double center[2], p[2];
  G_wait_click(center);
  G_wait_click(p);

  // declare variables
  double delta_x = abs(center[0] - p[0]);
  double delta_y = abs(center[1] - p[1]);
  double rad = sqrt((delta_x*delta_x) + (delta_y*delta_y));
  double rad_theta = ((M_PI)/180)*(360/n);
  double new_x = 0;
  double upper_new_y = 0;
  double lower_new_y = 0;
  double xs[100], upper_ys[100], lower_ys[100];
  int points = 21;
  double lower_center[2];
  int key;  
  lower_center[0] = center[0];
  lower_center[1] = (height-center[1]);
  // center point
  //G_rgb(0.0, 0.0, 0.0);
  //G_fill_circle(center[0], center[1], 2);
 // G_fill_circle(lower_center[0],lower_center[1],2);

  // put points into an array
  for(int i = 0; i < points; i++){
    rad_theta = (((M_PI)/180)*i)*(360/points);
    new_x = ((sin(rad_theta))*rad)+center[0];
    upper_new_y = (((cos(rad_theta))*rad)/4)+center[1];
    lower_new_y = (((cos(rad_theta))*rad)/4)+lower_center[1];
    xs[i] = new_x;
    upper_ys[i] = upper_new_y;
    lower_ys[i] = lower_new_y;
  }

  // draw the lines connecting the points
  for(int i = 0; i < sizeof(xs); i++){
    for(int j = 0; j < sizeof(xs); j++){
      if(j < points-1){
        G_rgb(1.0, 0.0, 0.0);
        G_line(xs[i],upper_ys[i], xs[j+i],upper_ys[j+i]);
        //G_rgb(0.0, 0.0, 0.0);
        //G_fill_circle(xs[i], upper_ys[i], 2);
        G_line(xs[i],lower_ys[i], xs[j+i],lower_ys[j+i]);
        //G_rgb(0.0, 0.0, 0.0);
        //G_fill_circle(xs[i], lower_ys[i], 2);
        G_rgb(0.0, 1.0, 0.0);
        G_line(xs[j],upper_ys[j], xs[j],lower_ys[j]);
      }
    
      if(j == points-i){
        G_rgb(1.0, 0.0, 0.0);
        G_line(xs[i],upper_ys[i], xs[0],upper_ys[0]);
        //G_rgb(0.0, 0.0, 0.0);
        //G_fill_circle(xs[i], upper_ys[i], 2);
        G_line(xs[i],lower_ys[i], xs[0],lower_ys[0]);
        //G_rgb(0.0, 0.0, 0.0);
        //G_fill_circle(xs[i], lower_ys[i], 2);
        G_rgb(0.0, 1.0, 0.0);
        G_line(xs[j],upper_ys[j], xs[j],lower_ys[j]);
      } 
    }
    key = G_wait_key();
    G_rgb(1.0, 1.0, 1.0);
    G_clear();
  }
   
  //key = G_wait_key();
  //G_rgb(1.0, 1.0, 1.0);
  //G_clear();

  //   // draw the lines connecting the points, shift 1
  // for(int i = 0; i < sizeof(xs)-2; i++){
  //   if(i < points-1){
  //     G_rgb(1.0, 0.0, 0.0);
  //     G_line(xs[i],upper_ys[i], xs[i+1],upper_ys[i+1]);
  //     //G_rgb(0.0, 0.0, 0.0);
  //     //G_fill_circle(xs[i], upper_ys[i], 2);
  //     G_line(xs[i],lower_ys[i], xs[i+1],lower_ys[i+1]);
  //     //G_rgb(0.0, 0.0, 0.0);
  //     //G_fill_circle(xs[i], lower_ys[i], 2);
  //     G_rgb(0.0, 1.0, 0.0);
  //     G_line(xs[i],upper_ys[i], xs[i+1],lower_ys[i+1]);
  //   }
  //   if(i == points-1){
  //     G_rgb(1.0, 0.0, 0.0);
  //     G_line(xs[i],upper_ys[i], xs[0],upper_ys[0]);
  //     //G_rgb(0.0, 0.0, 0.0);
  //     //G_fill_circle(xs[i], upper_ys[i], 2);
  //     G_line(xs[i],lower_ys[i], xs[0],lower_ys[0]);
  //     //G_rgb(0.0, 0.0, 0.0);
  //     //G_fill_circle(xs[i], lower_ys[i], 2);
  //     G_rgb(0.0, 1.0, (i/255.0));
  //     G_line(xs[i],upper_ys[i], xs[0],lower_ys[0]);
  //   }
  // }

  key = G_wait_key();
}