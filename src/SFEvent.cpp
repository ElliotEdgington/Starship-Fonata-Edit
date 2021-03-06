#include "SFEvent.h"
#include <iostream>

/**
 * Effectively wraps an SDL_Event in our custom event type.
 * Added more keybindings, also KeyDown and KeyUp to get when the action happens.
 */
SFEvent::SFEvent(const SDL_Event & event) {
  switch (event.type) {
  case SDL_QUIT:
    code = SFEVENT_QUIT;
    break;
  case SDL_USEREVENT:
    code = SFEVENT_UPDATE;
    break;
  case SDL_KEYDOWN:
    switch (event.key.keysym.sym) {
    case SDLK_UP:
    case SDLK_w:
      code = SFEVENT_PLAYER_UP_KEYDOWN;
      break;
    case SDLK_DOWN:
    case SDLK_s:
      code = SFEVENT_PLAYER_DOWN_KEYDOWN;
      break;
    case SDLK_LEFT:
    case SDLK_a:
      code = SFEVENT_PLAYER_LEFT_KEYDOWN;
      break;
    case SDLK_RIGHT:
    case SDLK_d:
      code = SFEVENT_PLAYER_RIGHT_KEYDOWN;
      break;
    case SDLK_RSHIFT:
    case SDLK_e:
    case SDLK_x:
      code = SFEVENT_WALL;
      break;
    case SDLK_SPACE:
    case SDLK_z:
      code = SFEVENT_FIRE_KEYDOWN;
      break;
    case SDLK_q:
      code = SFEVENT_QUIT;
      break;
    }
    break;
  case SDL_KEYUP:
    switch(event.key.keysym.sym){
    case SDLK_UP:
    case SDLK_w:
      code = SFEVENT_PLAYER_UP_KEYUP;
      break;
    case SDLK_DOWN:
    case SDLK_s:
      code = SFEVENT_PLAYER_DOWN_KEYUP;
      break;
    case SDLK_LEFT:
    case SDLK_a:
      code = SFEVENT_PLAYER_LEFT_KEYUP;
      break;
    case SDLK_RIGHT:
    case SDLK_d:
      code = SFEVENT_PLAYER_RIGHT_KEYUP;
      break;
    case SDLK_SPACE:
    case SDLK_z:
      code = SFEVENT_FIRE_KEYUP;
      break;
    }
    break;
  default:
    code = SFEVENT_NULL;
    break;
  }
}


SFEVENT SFEvent::GetCode() {
  return code;
}
