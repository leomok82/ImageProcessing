/**
 * Group Name: Yen
 * Antony Krymski (agk123)
 * Leo Mok (edsml-lm1823)
 * Bofan Liu (edsml-bl1023)
 * Zeyi Ke (edsml-zk23)
 * Tianzi Zhang (acse-tz2523)
 * Yifan Wu (acse-yw11823)
 */

#ifndef FILTERINPUTHANDLER_H
#define FILTERINPUTHANDLER_H

/**
 * @brief Applies a selected image processing filter to a 2D image.
 *
 * This function prompts the user to select a type of filter for image processing,
 * including options for colour correction, image blur, and edge detection. Depending
 * on the selected filter, further input may be requested from the user to specify
 * additional parameters (e.g., kernel size for blur filters). The selected filter is
 * then applied to the image data provided.
 *
 * Note: This function relies on user input from the standard input (std::cin) and
 * therefore is best suited for console applications.
 *
 * @param data A pointer to the image data array. This array is expected to contain
 *             the pixel data for the image, organized in row-major order, with each
 *             pixel represented by 'channels' number of unsigned char values.
 * @param width The width of the image in pixels.
 * @param height The height of the image in pixels.
 * @param channels The number of color channels in the image data (e.g., 3 for RGB, 4 for RGBA).
 *
 * @note The image data (`data`) is modified in place by the applied filter.
 */
class FilterInputHandler {
public:
    static void applyFilter(unsigned char* data, int width, int height, int channels);
};

#endif // FILTERINPUTHANDLER_H
