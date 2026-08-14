class Component;

class GameObject
{
private:
    static const int MAX_COMPONENTS = 15;
    Component* components_[MAX_COMPONENTS];

public:
    GameObject(/* args */);
    ~GameObject();

    void AddComponent(const Component& ComponentRef);
};

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}


class Component
{
private:
    /* data */
public:
    Component(/* args */);
    ~Component();
};

Component::Component(/* args */)
{
}

Component::~Component()
{
}
