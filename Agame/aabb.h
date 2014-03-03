#ifndef AABB_H
#define AABB_H

class AABB {
public:
    AABB();
    bool collision(AABB other) const;
public:
    int x, y, w, h;
};

#endif // AABB_H
