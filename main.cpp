#include <iostream>
#include <fstream>
#include <SDL2/SDL.h>
#include "generate.h"
#include "rainbow.h"

constexpr int SCREEN_WIDTH { 2736 }, SCREEN_HEIGHT { 1824 };
constexpr double length { 4 };
constexpr int iterations { 1000 };
// const bool bits[255] = {1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1};
//

int main( int argc, char *argv[] )
{
    int i, k;
    std::string theLine = "";
    // std::ofstream myFile;
    // myFile.open("output.txt");
    // k_max should be 65536
    for ( k = 1; k < iterations; k++ ) {
        std::string cur = toBits(k);
        // myFile << k << " in binary ->" << cur << std::endl;
        theLine += trimZeros( cur );
    }

    // std::cout << theLine << std::endl;
    size_t lineLength = theLine.length( );

    SDL_Init( SDL_INIT_EVERYTHING );

    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    SDL_Event windowEvent;

    SDL_CreateWindowAndRenderer( SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer );

    if ( window == NULL )
    {
        std::cout << "Cound not create window" << SDL_GetError( ) << std::endl;
        return 1;
    }

    if ( renderer == NULL )
    {
        std::cout << "Could not create renderer" << SDL_GetError( ) << std::endl;
        return 2;
    }    

    

    double x1 = 0, x2 = SCREEN_WIDTH / 2 - 512, y1 = 0, y2 = SCREEN_HEIGHT / 2;

    int current_direction = 0; // 0 for up, 1 for right, 2 for down, 3 for 
    
    // Set draw color to black
    SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
    // Draw whole screen as black
    SDL_RenderClear( renderer );

    // Set draw color to white
    SDL_SetRenderDrawColor( renderer , 255, 255, 255, 255 );

    for ( int i = 0; i < lineLength; i++ ) {
        // std::cout << "bit[" << i << "]: " << theLine[i] << std::endl;
        if ( theLine[i] == '0' )
        {
            current_direction = ( current_direction + 1 ) % 4;
        }
        else 
        { // a 1
            x1 = x2;
            y1 = y2;
            switch ( current_direction ) {
                case 0: // up
                    y2 = y1 + length;
                    break;
                case 1: // right
                    x2 = x1 + length;
                    break;
                case 2: // down
                    y2 = y1 - length;
                    break;
                case 3: // left
                    x2 = x1 - length;
                    break;
                default:
                    std::cerr << "INVALID DIRECTION!";
            }
            
        }
        SDL_RenderDrawLine ( renderer, (int)x1, (int)y1, (int)x2, (int)y2 );
    }
    

    SDL_RenderPresent( renderer );


    /// TESTING RAINBOW

    for (i = 0; i < Num_Colors_Of_Rainbow; i++)
    {
        std::cout << ""
    }

        //////

    while (true)
    {
        if (SDL_PollEvent(&windowEvent))
        {
            if (windowEvent.type == SDL_QUIT)
            {
                break;
            }

            if (windowEvent.type == SDL_KEYDOWN)
            {
                if (windowEvent.key.keysym.sym == SDLK_ESCAPE)
                {
                    break;
                }
            }
        }
    }

    /*
    while ( true )
    {
        if ( SDL_PollEvent( &windowEvent ) )
        {
            if ( windowEvent.type == SDL_QUIT )
            { break; }
        }


        // Set draw color to black
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        // Draw whole screen as black
        SDL_RenderClear(renderer);

        // Set draw color to white
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        for (int i = 0; i < lineLength; i++) {
            // std::cout << "bit[" << i << "]: " << theLine[i] << std::endl;
            if (theLine[i] == '0') {
                current_direction = (current_direction + 1) % 4;
            }
            else { // a 1
                x1 = x2;
                y1 = y2;
                switch (current_direction) {
                    case 0: // up
                        y2 = y1 + 10;
                        break;
                    case 1: // right
                        x2 = x1 + 10;
                        break;
                    case 2: // down
                        y2 = y1 - 10;
                        break;
                    case 3: // left
                        x2 = x1 - 10;
                        break;
                    default:
                        std::cerr << "INVALID DIRECTION!";
                }
                
            }
            SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
            SDL_Delay(5);
        }
        

        SDL_RenderPresent(renderer);

        

    }
    */


    SDL_DestroyWindow(window);
    SDL_Quit( );
    
    return EXIT_SUCCESS;
}