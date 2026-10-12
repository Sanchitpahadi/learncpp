#include <iostream>
#include <unordered_map>
#include <typeindex>
#include <any>

using Entity = int;  

struct Position 
{
    float x,y,z;
};
struct Velocity
{
    float dy,dx;
};
struct Health
{
    int hp;
};
class Scene
{
public:

    Entity createEntity() {return nextId_++;}

    template<typename T>
    void addComponent(Entity e, T component)
    {
        pools_[std::type_index(typeid(T))][e] = component;
    }

    template<typename T>
    bool hasComponent(Entity e)
    {
        auto it = pools_.find(std::type_index(typeid(T)));
        if(it == pools_.end()) return false;
        return it->second.find(e) != it->second.end();
    }

    template<typename T>
    T& getComponent(Entity e)
    {
        return std::any_cast<T&>(pools_[std::type_index(typeid(T))].at(e));
    }
    private:
    Entity nextId_ = 0;
    std::unordered_map<std::type_index,std::unordered_map<Entity,std::any>> pools_;
};
int main()
{
    Scene scene;
    
    Entity player = scene.createEntity();

    scene.addComponent(player,Position{0,0});

    scene.addComponent(player,Velocity{1,0});

    scene.addComponent(player,Health{200});

    Entity rock = scene.createEntity();

    scene.addComponent(rock,Position{5,5});

    for(Entity e : {player,rock})
    {
        if (scene.hasComponent<Position>(e) && scene.hasComponent<Velocity>(e))
        {
            auto& pos = scene.getComponent<Position>(e);
            auto& vel = scene.getComponent<Velocity>(e);

            pos.x += vel.dx;
            pos.y += vel.dy;
        std::cout << "Entity " << e << " moved to (" << pos.x << ", " << pos.y << ")\n";
        }
        else
        {
        std::cout << "Entity " << e << "did not move \n";

        }
    }

    return 0;
}