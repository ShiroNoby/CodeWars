#pragma
#include <vector>

using vec = std::vector< std::vector<int> >;

namespace BattleShip{

    struct Point {
        int x;
        int y;

        Point(int x = 0, int y = 0) : x(x), y(y) {}
    };

    struct Ship {
        
        // +1   -1
        //0000 00100
        //1111 00100
        //0000 00100
        int m_horisontal;
        int m_size;


        std::vector<Point> ship;

        Ship(int size = 0, int horisontal = 0) : m_size(size), m_horisontal(horisontal), ship(m_size) {}
    };

    struct BattleField{

        std::vector<Ship> field;

        void addShip(Ship &ship) {field.push_back(ship);}
        void reset(){field.clear();}
    } Bfield;

    bool make_ship(vec &field, int x, int y)
    {
        //check ships environment
        //std::vector<Point> bound;
        //, bound( 8 + (2 * ( m_size - 1)))

        Ship tmp(1);
        int size = field.size();

        field[y][x] = 2;
        tmp.ship[0].x = x;
        tmp.ship[0].y = y;

        //os +1 horisontal | -1 vertical
        int os = 0;

        auto script = [&](int xx, int yy, bool &work, int check, int validHorisont)
        {
            int& i_tmp = field[yy][xx];

            if(i_tmp == 1)
            {
                if(tmp.m_horisontal == check) return false;
                tmp.m_horisontal = validHorisont;
                os += validHorisont;

                work = true;
                i_tmp = 2;
                ++tmp.m_size;
                tmp.ship.push_back({ xx, yy });
            }

            return true;
        };

        //make ship
        // 1 - ship? | 2 - ship | 0 empty
        for(int point = 1; point < 4; ++point) 
        {
            bool work = false;

            //horisontal
            if(os >= 0) 
            {                
                //right
                if((x + point) < size) 
                    if(field[y][x + point] == 1) 
                        if(!script(x + point, y, work, -1, 1)) 
                            return false;

                //left
                if((x - point) >= 0) 
                    if(field[y][x - point] == 1) 
                        if(!script(x - point, y, work, -1, 1))
                            return false;
            }

            //vertical
            if(os <= 0) 
            {                
                //down
                if((y + point) < size) 
                    if(field[y + point][x] == 1) 
                        if(!script(x, y + point, work, 1, -1))
                            return false;

                //up
                if((y - point) >= 0) 
                    if(field[y - point][x] == 1) 
                        if(!script(x, y - point, work, 1, -1))
                            return false;
            }

            if(!work) break;
        }

        auto tetraCheck = [&](int x, int y)
        {
            if(x < 0 || x >= size) return false;
            if(y < 0 || y >= size) return false;
            if (field[y][x] == 0 || field[y][x] == 2) return false;

            return true;
        };

        //check environment
       for (int index = 0; index < tmp.m_size; ++index)
       {
           //up
           if ((y - 1) >= 0)
               if (tetraCheck(x, y - 1))
                   return false;
                       
           //down
           if ((y + 1) < size)
               if (tetraCheck(x, y + 1))
                   return false;

           //right
           if ((x + 1) < size)
           {
               if (tetraCheck(x + 1, y)) return false;

               //up
               if (tetraCheck(x + 1, y - 1)) return false;

               //down
               if (tetraCheck(x + 1, y + 1)) return false;
           }

           //left
           if ((x - 1) >= 0)
           {
               if (tetraCheck(x - 1, y)) return false;

               //up
               if (tetraCheck(x - 1, y - 1)) return false;

               //down
               if (tetraCheck(x - 1, y + 1)) return false;
           }

           if (tmp.m_horisontal == 1) ++x;
           if (tmp.m_horisontal == -1) ++y;    
       }

        Bfield.field.push_back(tmp);

        return true;
    }
}; //BattleShip


bool validate_battlefield(vec field)
{
    using namespace BattleShip;

    Bfield.reset();
    
    //make ships
    int size = field.size();
    for(int y = 0; y < size; ++y) 
        for( int x = 0; x < size; ++x ) 
            if(field[y][x] == 1) 
                if(!make_ship(field, x, y)) 
                    return false;


    //check ships valid size
    {
        int max_size = 5;
        int ships[5] = {0};
        
        for (auto elem : Bfield.field)
        {
            ++ships[elem.m_size]; 
        }

        for(int index = 1 ; index < 5; ++index) 
        {
            if( ships[index] != max_size - index ) return false;
        }
    }

    return true;
}