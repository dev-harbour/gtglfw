/*
 *
 */

#include "gtglfw.h"

int main()
{
   App *app = gtCreateWindow( 512, 512, "Optical illusion" );

   gtBackground( app, 0x0 );

   while( ! gtMainLoop( app ) )
   {
      BEGINDRAWING( app );

      int pointSize = 16;
      int gridWidth = app->width / pointSize;
      int gridHeight = app->height / pointSize;

      // Initializing an array to track occupied points
      bool occupiedPoints[ gridWidth ][ gridHeight ];
      for( int x = 0; x < gridWidth; x++ )
      {
         for( int y = 0; y < gridHeight; y++ )
         {
            occupiedPoints[ x ][ y ] = F;
         }
      }

      int centerX = app->width / 2;
      int centerY = app->height / 2;
      int radius = 150;
      int outerBoundary = radius + 50;

      // Draw random points inside a circle
      for( int i = 0; i < 8000; ++i )
      {
         double angle = ( double ) rand() / RAND_MAX * 2 * M_PI;
         double r = sqrt( ( double ) rand() / RAND_MAX ) * radius;
         int x = centerX + r * cos( angle );
         int y = centerY + r * sin( angle );
         gtPointSize( x, y, 2, 0x670100 );
      }

      // Drawing random points outside the circle
      for( int i = 0; i < 600; ++i )
      {
         int gridX = rand() % gridWidth;
         int gridY = rand() % gridHeight;
         int x = gridX * pointSize;
         int y = gridY * pointSize;
         int distFromCenter = sqrt( pow( x - centerX, 2 ) + pow( y - centerY, 2 ) );

         if( distFromCenter > outerBoundary && ! occupiedPoints[ gridX ][ gridY ] )
         {
            gtPointSize( x, y, pointSize, 0xFFFFFF );
            occupiedPoints[ gridX ][ gridY ] = T;
         }
      }

      ENDDRAWING( app );
      gtWaitEvents();
   }

   gtCloseAll( app );
}
