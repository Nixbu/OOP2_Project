#include "CollisionHandling.h"


HitMap initializeCollisionMap()
{
    HitMap collisionMap;
    collisionMap[Key(typeid(Candy), typeid(Bubble))] = &candyBubble;
   // collisionMap[Key(typeid(Bubble), typeid(Candy))] = &bubbleCandy;

    return collisionMap;
}

HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2)
{
    static HitMap collisionMap = initializeCollisionMap();
    auto mapEntry = collisionMap.find(std::make_pair(class1, class2));
    if (mapEntry == collisionMap.end())
    {
        return nullptr;
    }
    return mapEntry->second;
}

void candyBubble(std::shared_ptr<GameObject> object1, std::shared_ptr<GameObject> object2, b2World& world)
{
     std::shared_ptr<Candy> candy = std::dynamic_pointer_cast<Candy>(object1);
     std::shared_ptr<Bubble> bubble = std::dynamic_pointer_cast<Bubble>(object2);

    bubble->changeToDynamic();
    candy->SetLinearVelocity(BUBBLE_VELOCITY);



    b2WeldJointDef weldJointDef;
    weldJointDef.bodyA = bubble->getBody();
    weldJointDef.bodyB = candy->getBody();
    weldJointDef.localAnchorA.Set(0, 0);
    weldJointDef.localAnchorB.Set(0, 0);


    world.CreateJoint(&weldJointDef);


}


