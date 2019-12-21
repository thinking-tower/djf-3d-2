namespace djf_3d {

enum class Axis {
    X, // left/right axis (horizontal, paralell to screen)
    Y, // near/far axis (horizontal, perpendicular to screen)
    Z  // up/down axis (vertical)
};

class CoordTriple {
private:
    float x_pos; // left/right
    float y_pos; // close/far
    float z_pos; // up/down

public:
    CoordTriple(
        const float x,
        const float y,
        const float z
    );

    ~CoordTriple(void);

    /**
     * This returns the value of one of a CoordTriple's
     * properties.
     *
     * @param axis whether the axis is X, Y, or Z
     * @return x_pos, y_pos, or z_pos, according to the axis
     */
    float get_pos(const Axis axis) const;

    /**
     * This translates the CoordTriple along one of the axes.
     *
     * @param axis which axis to move along
     * @param amount the amount by which to move
     */
    void translate(const Axis axis, const float amount);

    /**
     * This rotates the CoordTriple about one of the three axes
     * of three-dimensional space.
     *
     * @param axis which axis to rotate around
     * @param axis_point point to rotate around
     * @param theta_degrees number of degrees to rotate
     */
    void rotate_3d(
        const Axis axis,
        const CoordTriple *axis_point,
        const float theta_degrees
    );


    /* IMPORTANT: REGARDING project_2d_x() AND project_2d_y().

       Pay special note to the value selected for `fov`; this
       parameter specifies the degree to which a point's
       distance from the viewer makes it appear to be closer to
       the vanishing point. Values between 800-1200 are
       recommended; lower than that causes a "fish-eye" effect,
       and higher than that causes things to look exaggeratedly
       flat, like medieval art that lacks perspective. */

    /**
     * This returns the x-position correpsonding to the 2d
     * projection of the CoordTriple.
     *
     * @param vanish_x 2d x-coordinate of the vanishing point
     * @param fov the field of view
     * @return 2d projection x-coordinate
     */
    float project_2d_x(
        const float vanish_x,
        const float fov
    ) const;

    /**
     * This returns the y-position correpsonding to the 2d
     * projection of the CoordTriple.
     *
     * @param vanish_y 2d y-coordinate of the vanishing point
     * @param fov degree of perspective distortion
     * @return 2d projection y-coordinate
     */
    float project_2d_y(
        const float vanish_y,
        const float fov
    ) const;
};

} // end of namespace djf_3d
