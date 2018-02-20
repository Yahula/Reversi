#ifndef DISK_H_
#define DISK_H_

/**
 * Class Disk - created by the player to represent a player move
 */
class Disk {
public:
    /**
     * Constructor
     * @param r - row location of the desired move
     * @param c - column location of the desired move
     * @param p - player "id" - (-1) for black player, 1 for white player
     */
    Disk(int r, int c, int p);

    /**
     * copy constructor.
     * @param d a Disk to copy.
     */
    Disk(Disk *d);

    /**
     * default constructor.
     */
    Disk();

    /**
     * Distructor
     */
    virtual ~Disk();

    /**
     * @return the c value of the disk
     */
    int getCol() const;

    /**
     * @return the player "id"
     */
    int getPlayer() const;

    /**
     * @return the r value of the disk
     */
    int getRow() const;

    /**
     * sets the c value
     * @param col - the desired new column location
     */
    void setCol(int col);

    /**
     * sets the r value
     * @param row - the new desired row location
     */
    void setRow(int row);

    /**
     * sets the player that placed the disk (the color of the disk).
     * @param p
     */
    void setPlayer(int p);

private:
    /**
     * row location of the disk
     */
    int row;

    /**
     * column location of the disk
     */
    int col;

    /**
     * player id
     */
    int player;
};

#endif /* DISK_H_ */
