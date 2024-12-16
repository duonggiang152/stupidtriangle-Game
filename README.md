# Triangle - Game (follow tutorial of the chernol)  


<space><space>


# Game Engine Architecture


<space><space>


![image](https://github.com/user-attachments/assets/18e6f395-4b3c-4778-b852-39c97275b71e)


<space><space>
Application class control very thing inside a window. You can extend this class to modify your own class.
It contain multiple layer which can represent for rendering different thing.


<space><space>
For example in this game, I have a single layer for rendering. But we can seperate different layer for rendering background, rendering other background, NPC, ... 




<space><space>
# Event Architecture


<space><space>
![image](https://github.com/user-attachments/assets/2ae45205-6b56-433d-8e5e-caad5c279bec)


<space><space>
Window abstract class is the interface that helps engine can adapt with multiple platform: windows, linux, mac ...


Depend on the platform multiple concreate class will be create. It make platform code dependent with game logic code


<space><space>
