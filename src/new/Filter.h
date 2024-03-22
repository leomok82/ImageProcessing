/**
 * Group Name: Yen
 * Antony Krymski (agk123)
 * Leo Mok (edsml-lm1823)
 * Bofan Liu (edsml-bl1023)
 * Zeyi Ke (edsml-zk23)
 * Tianzi Zhang (acse-tz2523)
 * Yifan Wu (acse-yw11823)
 */

#ifndef FILTER_H
#define FILTER_H

class Filter {
public:
    virtual ~Filter() {}
    virtual void apply(unsigned char* data, int width, int height, int channels) = 0;
};

#endif // FILTER_H
