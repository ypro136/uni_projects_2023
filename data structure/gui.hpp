#ifndef GUI_HEADER
#define GUI_HEADER


#include "raylib/src/raylib.h"
#include "Music_player.hpp"



class button{
    public:
    int button_State = 0;               // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
    bool button_Action = false;         // Button action should be activated
    Rectangle Bounds;
    void (*function)();
    MusicPlayer* music_player;
    string name;


    button (float _width, float _height, string _name, Rectangle _Bounds, void (*_function)())
    {
        Bounds = _Bounds;
        function = _function;
        name = _name;
    } 
    button ()
    {
        
    }

};

class gui {
public:
    
    const int screen_Width = 800;
    const int screen_Height = 500;

    DLL<button*>* button_List = new DLL<button*>();

    gui () 
    {
        InitWindow(screen_Width, screen_Height, "Music Player");

        // to implement audio device

        SetTargetFPS(60);
    }

    void destroy()
    {
        // De-Initialization
        CloseWindow();          // Close window and OpenGL context
    }

    void button_states(bool state)
    {

        button *current_button = new button();
        for (int i = 0; i < button_List->Count(); i++)
        {
            
            current_button = button_List->NodeAt(i)->value;
            current_button->button_State = state;
            
        }
    }


    void Init_event_sys()
    {
        Vector2 mousePoint = { 0.0f, 0.0f };
    }

    void run_events()
    {
        Init_event_sys();
        button_states(0);
        update_states();


    }

    void do_actions ()
    {
        button *current_button = new button();

        for (int i = 0; i < button_List->Count(); i++)
        {
            
            current_button = button_List->NodeAt(i)->value;
            if (current_button->button_Action)
            {
                current_button->function();
                current_button->button_Action = false;
            }
        }
    }

    void update_states()
    {
        button *current_button = new button();
        Vector2 mousePoint = GetMousePosition();
        

        for (int i = 0; i < button_List->Count(); i++)
        {
            current_button = button_List->NodeAt(i)->value;
            if (CheckCollisionPointRec(mousePoint, current_button->Bounds))
            {
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) 
                {
                    current_button->button_State = 2;
                }
                else 
                {
                    current_button->button_State = 1;
                }
                if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) 
                {
                    current_button->button_Action = true;
                }
            }
        else current_button->button_State = 0;
        }
    }

    button* create_button (Vector2 position, Vector2 size, string button_name , void (*_function)())
    {
        Rectangle sourceRec = { 0, 0, size.x, size.y };
        Rectangle buttonBounds = { position.x - size.x/2.0f, position.y - size.y/2.0f, size.x, size.y };
        button *temp = new button(size.x, size.y, button_name, buttonBounds, _function);
        button_List->Insert(temp);
        return temp;
    }

    void draw_button (button* button, string text, Color _color)
    {
        Rectangle buttonBounds = button->Bounds;
        float inset = 1.1;
        int offset_color = 200;
        Color color;

        buttonBounds.height *= inset;
        buttonBounds.width *= inset;
        color.a = 100;
        color.b = offset_color;
        color.r = offset_color;
        color.g = offset_color;
        DrawRectangleRounded(buttonBounds,0.1 ,1 , color);
        
        _color.a = 200;

        buttonBounds = button->Bounds;
        DrawRectangleRounded(buttonBounds,0.1 ,1 , _color);

        DrawText(button->name.c_str(), buttonBounds.x + 15 , buttonBounds.y + 15, 20, WHITE);

    };
    




};

#endif