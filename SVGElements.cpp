#include "SVGElements.hpp"

namespace svg
{
    // These must be defined!
    SVGElement::SVGElement() {}
    SVGElement::~SVGElement() {}

    // Ellipse (initial code provided)
    Ellipse::Ellipse(const Color &fill,
                     const Point &center,
                     const Point &radius)
        : fill(fill), center(center), radius(radius)
    {
    }
    void Ellipse::draw(PNGImage &img) const
    {
        img.draw_ellipse(center, radius, fill);
    }
    // @todo provide the implementation of SVGElement derived classes
    // HERE -->

    void Ellipse::translate(const Point &t)
    {
        center = center.translate(t);
    }

    void Ellipse::rotate(const Point &origin, int degrees)
    {
        // PDF deviation: for ellipses we only rotate the center,
        // we do NOT change orientation of the ellipse itself.
        center = center.rotate(origin, degrees);
    }

    void Ellipse::scale(const Point &origin, int factor)
    {
        center = center.scale(origin, factor);
        radius.x *= factor;
        radius.y *= factor;
    }

    SVGElement* Ellipse::clone() const
    {
        return new Ellipse(*this);
    }

    // Build the parent (Ellipse) with rx = ry = r.
    Circle::Circle(const Color &fill, const Point &center, int r)
        : Ellipse(fill, center, {r, r}) {}

    SVGElement* Circle::clone() const
    {
        return new Circle(*this);
    }

}
