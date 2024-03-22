#include <iostream>

#include "EdgeDetectionFilter.h"
#include "Filter.h"
#include "Image.h"
#include "ColourFilterCorrection.h"
#include "ImageBlurFilter.h"
#include "Volume.h"
#include "Filter3D.h"
#include "Projections.h"
#include "FilterInputHandler3D.h"


class GenerateImages{
    public:
        GenerateImages(){
            generateSlices();
            //generateImages3D();
            // generateImages3D();
        }
        void generateImages2D(){
            // 1 - greyscale
            // Gracehopper
            std::string input_path =" ../Images/gracehopper.png";
            std::unique_ptr<Filter> filter = ColourCorrectionFilter::create(1);
            std::string path = "../Output/1-grayscale/gracehopper.png";
            applyFilter(input_path, filter, path);

            // Tienshan
            input_path = "../Images/tienshan.png";
            filter = ColourCorrectionFilter::create(1);
            path = "../Output/1-grayscale/tienshan.png";
            applyFilter(input_path, filter, path);

            // 2 - brightness
            // Gracehopper -100
            input_path = "../Images/gracehopper.png";
            filter = std::make_unique<BrightnessFilter>(-100); 
            path = "../Output/2-brightness/gracehopper_minus100.png";
            applyFilter(input_path, filter, path);

            // Gracehopper+100
            
            input_path = "../Images/gracehopper.png";
            filter = std::make_unique<BrightnessFilter>(100);
            path = "../Output/2-brightness/gracehopper_plus100.png";
            applyFilter(input_path, filter, path);

            //Stinkbug-50
            input_path = "../Images/stinkbug.png";
            filter = std::make_unique<BrightnessFilter>(-50);
            path = "../Output/2-brightness/stinkbug_minus50.png";
            applyFilter(input_path, filter, path);

            //Stinkbug+50
            input_path = "../Images/stinkbug.png";
            filter = std::make_unique<BrightnessFilter>(50);
            path = "../Output/2-brightness/stinkbug_plus50.png";
            applyFilter(input_path, filter, path);


            // 3 - histogram equalisation
            input_path = "../Images/vh_anatomy.png";
            filter = std::make_unique<HistogramEqualizerFilter>(true); //hsl
            path = "../Output/3-histogram/vh_anatomy_hsl.png";
            applyFilter(input_path, filter, path);

            // anatomy HSV
            input_path = "../Images/vh_anatomy.png";
            filter = std::make_unique<HistogramEqualizerFilter>(false); //hsv
            path = "../Output/3-histogram/vh_anatomy_hsv.png";
            applyFilter(input_path, filter, path);

            // ct grey
            input_path = "../Images/vh_ct.png";
            filter = std::make_unique<HistogramEqualizerFilter>(); //grey
            path = "../Output/3-histogram/vh_ct.png";
            applyFilter(input_path, filter, path);

            // 4 - thresholding
            // stinkbug grey
            input_path = "../Images/stinkbug.png";
            filter = std::make_unique<ThresholdingFilter>(80); //grey
            path = "../Output/4-thresholding/stinkbug_80.png";
            applyFilter(input_path, filter, path);

            //tienshan HSL
            input_path = "../Images/tienshan.png";
            filter = std::make_unique<ThresholdingFilter>(127, true); //hsl
            path = "../Output/4-thresholding/tienshan_HSL_127.png";
            applyFilter(input_path, filter, path);

            //tienshan HSV
            input_path = "../Images/tienshan.png";
            filter = std::make_unique<ThresholdingFilter>(127, false); //hsl
            path = "../Output/4-thresholding/tienshan_HSV_127.png";
            applyFilter(input_path, filter, path);

            //ct grey
            input_path = "../Images/vh_ct.png";
            filter = std::make_unique<ThresholdingFilter>(80); //grey
            path = "../Output/4-thresholding/vh_ct_80.png";
            applyFilter(input_path, filter, path);

            // 5 - salt and pepper noise
            //gracehopper 10
            input_path = "../Images/gracehopper.png";
            filter = std::make_unique<SaltAndPepperNoiseFilter>(0.1); //grey
            path = "../Output/5-noise/gracehopper_10.png";
            applyFilter(input_path, filter, path);

            //gracehopper 25
            input_path = "../Images/gracehopper.png";
            filter = std::make_unique<SaltAndPepperNoiseFilter>(0.25); //grey
            path = "../Output/5-noise/gracehopper_25.png";
            applyFilter(input_path, filter, path);

            //stinkbug 10
            input_path = "../Images/stinkbug.png";
            filter = std::make_unique<SaltAndPepperNoiseFilter>(0.1); //grey
            path = "../Output/5-noise/stinkbug_10.png";
            applyFilter(input_path, filter, path);

            //stinkbug 40
            input_path = "../Images/stinkbug.png";
            filter = std::make_unique<SaltAndPepperNoiseFilter>(0.4); //grey
            path = "../Output/5-noise/stinkbug_40.png";
            applyFilter(input_path, filter, path);

            // 6.1 - box blur
            //stinkbug 3x3 
            input_path = "../Images/stinkbug.png";
            filter = std::make_unique<BoxBlurFilter>(3); //grey
            path = "../Output/6-blur/box/stinkbug_3x3.png";
            applyFilter(input_path, filter, path);

            //stinkbug 5x5
            input_path = "../Images/stinkbug.png";
            filter = std::make_unique<BoxBlurFilter>(5); //grey
            path = "../Output/6-blur/box/stinkbug_5x5.png";
            applyFilter(input_path, filter, path);

            //tienshan 3x3
            input_path = "../Images/tienshan.png";
            filter = std::make_unique<BoxBlurFilter>(3); //grey
            path = "../Output/6-blur/box/tienshan_3x3.png";
            applyFilter(input_path, filter, path);

            //tienshan 5x5
            input_path = "../Images/tienshan.png";
            filter = std::make_unique<BoxBlurFilter>(5); //grey
            path = "../Output/6-blur/box/tienshan_5x5.png";
            applyFilter(input_path, filter, path);

            //vh_anatomy_sp15 3x3
            input_path = "../Images/vh_anatomy_sp15.png";
             filter = std::make_unique<BoxBlurFilter>(3); //grey
            path = "../Output/6-blur/box/vh_anatomy_sp15_3x3.png";
            applyFilter(input_path, filter, path);

            //vh_anatomy_sp15 5x5
            input_path = "../Images/vh_anatomy_sp15.png";
             filter = std::make_unique<BoxBlurFilter>(5); //grey
            path = "../Output/6-blur/box/vh_anatomy_sp15_5x5.png";

            // 6.2 - gaussian blur
            //stinkbug 3x3
            input_path = "../Images/stinkbug.png";
            filter = std::make_unique<GaussianBlurFilter>(3, 2); //grey
            path = "../Output/6-blur/gaussian/stinkbug_3x3.png";
            applyFilter(input_path, filter, path);

            //stinkbug 5x5
            input_path = "../Images/stinkbug.png";
             filter = std::make_unique<GaussianBlurFilter>(5, 2); //grey
            path = "../Output/6-blur/gaussian/stinkbug_5x5.png";
            applyFilter(input_path, filter, path);

            //tienshan 3x3
            input_path = "../Images/tienshan.png";
             filter = std::make_unique<GaussianBlurFilter>(3,2); //grey
            path = "../Output/6-blur/gaussian/tienshan_3x3.png";
            applyFilter(input_path, filter, path);

            //tienshan 5x5
            input_path = "../Images/tienshan.png";
             filter = std::make_unique<GaussianBlurFilter>(5, 2); //grey
            path = "../Output/6-blur/gaussian/tienshan_5x5.png";
            applyFilter(input_path, filter, path);

            //vh_anatomy_sp15 3x3
            input_path = "../Images/vh_anatomy_sp15.png";
             filter = std::make_unique<GaussianBlurFilter>(3, 2); //grey
            path = "../Output/6-blur/gaussian/vh_anatomy_sp15_3x3.png";
            applyFilter(input_path, filter, path);

            //vh_anatomy_sp15 5x5
            input_path = "../Images/vh_anatomy_sp15.png";
             filter = std::make_unique<GaussianBlurFilter>(5, 2); //grey
            path = "../Output/6-blur/gaussian/vh_anatomy_sp15_5x5.png";
            applyFilter(input_path, filter, path);

            //6.3 - Median Blur
            //stinkbug 3x3
            input_path = "../Images/stinkbug.png";
             filter = std::make_unique<MedianBlurFilter>(3); //grey
            path = "../Output/6-blur/median/stinkbug_3x3.png";
            applyFilter(input_path, filter, path);

            //stinkbug 5x5
            input_path = "../Images/stinkbug.png";
             filter = std::make_unique<MedianBlurFilter>(5); //grey
            path = "../Output/6-blur/median/stinkbug_5x5.png";
            applyFilter(input_path, filter, path);

            //tienshan 3x3
            input_path = "../Images/tienshan.png";
             filter = std::make_unique<MedianBlurFilter>(3); //grey
            path = "../Output/6-blur/median/tienshan_3x3.png";
            applyFilter(input_path, filter, path);
            
            //tienshan 5x5
            input_path = "../Images/tienshan.png";
             filter = std::make_unique<MedianBlurFilter>(5); //grey
            path = "../Output/6-blur/median/tienshan_5x5.png";
            applyFilter(input_path, filter, path);

            //vh_anatomy_sp15 3x3
            input_path = "../Images/vh_anatomy_sp15.png";
             filter = std::make_unique<MedianBlurFilter>(3); //grey
            path = "../Output/6-blur/median/vh_anatomy_sp15_3x3.png";
            applyFilter(input_path, filter, path);

            //vh_anatomy_sp15 5x5
            input_path = "../Images/vh_anatomy_sp15.png";
             filter = std::make_unique<MedianBlurFilter>(5); //grey
            path = "../Output/6-blur/median/vh_anatomy_sp15_5x5.png";
            applyFilter(input_path, filter, path);

            // 7.1 - prewitt edge detection
            //dimorphos
            input_path = "../Images/dimorphos.png";
             filter = std::make_unique<PrewittFilter>();
            path = "../Output/7-edge/prewitt/dimorphos.png";
            applyFilter(input_path, filter, path);

            //gracehopper
            input_path = "../Images/gracehopper.png";
             filter = std::make_unique<PrewittFilter>();
            path = "../Output/7-edge/prewitt/gracehopper.png";
            applyFilter(input_path, filter, path);
            
            //stinkbug
            input_path = "../Images/stinkbug.png";
             filter = std::make_unique<PrewittFilter>();
            path = "../Output/7-edge/prewitt/stinkbug.png";
            applyFilter(input_path, filter, path);

            //tienshan
            input_path = "../Images/tienshan.png";
             filter = std::make_unique<PrewittFilter>();
            path = "../Output/7-edge/prewitt/tienshan.png";
            applyFilter(input_path, filter, path);

            //vh_anatomy
            input_path = "../Images/vh_anatomy.png";
             filter = std::make_unique<PrewittFilter>();
            path = "../Output/7-edge/prewitt/vh_anatomy.png";
            applyFilter(input_path, filter, path);

            //vh_ct
            input_path = "../Images/vh_ct.png";
             filter = std::make_unique<PrewittFilter>();
            path = "../Output/7-edge/prewitt/vh_ct.png";
            applyFilter(input_path, filter, path);

            // 7.2 - Roberts Cross edge detection
            //dimorphos
            input_path = "../Images/dimorphos.png";
             filter = std::make_unique<RobertsCrossFilter>();
            path = "../Output/7-edge/roberts/dimorphos.png";
            applyFilter(input_path, filter, path);

            //gracehopper
            input_path = "../Images/gracehopper.png";
             filter = std::make_unique<RobertsCrossFilter>();
            path = "../Output/7-edge/roberts/gracehopper.png";
            applyFilter(input_path, filter, path);
            
            //stinkbug
            input_path = "../Images/stinkbug.png";
             filter = std::make_unique<RobertsCrossFilter>();
            path = "../Output/7-edge/roberts/stinkbug.png";
            applyFilter(input_path, filter, path);

            //tienshan
            input_path = "../Images/tienshan.png";
             filter = std::make_unique<RobertsCrossFilter>();
            path = "../Output/7-edge/roberts/tienshan.png";
            applyFilter(input_path, filter, path);

            //vh_anatomy
            input_path = "../Images/vh_anatomy.png";
             filter = std::make_unique<RobertsCrossFilter>();
            path = "../Output/7-edge/roberts/vh_anatomy.png";
            applyFilter(input_path, filter, path);

            //vh_ct
            input_path = "../Images/vh_ct.png";
             filter = std::make_unique<RobertsCrossFilter>();
            path = "../Output/7-edge/roberts/vh_ct.png";
            applyFilter(input_path, filter, path);

            // 7.3 - Scharr edge detection
            //dimorphos 
            input_path = "../Images/dimorphos.png";
             filter = std::make_unique<ScharrFilter>();
            path = "../Output/7-edge/scharr/dimorphos.png";
            applyFilter(input_path, filter, path);

            //gracehopper
            input_path = "../Images/gracehopper.png";
             filter = std::make_unique<ScharrFilter>();
            path = "../Output/7-edge/scharr/gracehopper.png";
            applyFilter(input_path, filter, path);

            //stinkbug
            input_path = "../Images/stinkbug.png";
             filter = std::make_unique<ScharrFilter>();
            path = "../Output/7-edge/scharr/stinkbug.png";
            applyFilter(input_path, filter, path);

            //tienshan
            input_path = "../Images/tienshan.png";
             filter = std::make_unique<ScharrFilter>();
            path = "../Output/7-edge/scharr/tienshan.png";
            applyFilter(input_path, filter, path);

            //vh_anatomy
            input_path = "../Images/vh_anatomy.png";
             filter = std::make_unique<ScharrFilter>();
            path = "../Output/7-edge/scharr/vh_anatomy.png";
            applyFilter(input_path, filter, path);

            //vh_ct
            input_path = "../Images/vh_ct.png";
             filter = std::make_unique<ScharrFilter>();
            path = "../Output/7-edge/scharr/vh_ct.png";
            applyFilter(input_path, filter, path);

            // 7.4 - Sobel edge detection
            //dimorphos
            input_path = "../Images/dimorphos.png";
             filter = std::make_unique<SobelFilter>();
            path = "../Output/7-edge/sobel/dimorphos.png";
            applyFilter(input_path, filter, path);

            //gracehopper
            input_path = "../Images/gracehopper.png";
             filter = std::make_unique<SobelFilter>();
            path = "../Output/7-edge/sobel/gracehopper.png";
            applyFilter(input_path, filter, path);

            //stinkbug
            input_path = "../Images/stinkbug.png";
             filter = std::make_unique<SobelFilter>();
            path = "../Output/7-edge/sobel/stinkbug.png";
            applyFilter(input_path, filter, path);

            //tienshan
            input_path = "../Images/tienshan.png";
             filter = std::make_unique<SobelFilter>();
            path = "../Output/7-edge/sobel/tienshan.png";
            applyFilter(input_path, filter, path);

            //vh_anatomy
            input_path = "../Images/vh_anatomy.png";
             filter = std::make_unique<SobelFilter>();
            path = "../Output/7-edge/sobel/vh_anatomy.png";
            applyFilter(input_path, filter, path);

            //vh_ct
            input_path = "../Images/vh_ct.png";
             filter = std::make_unique<SobelFilter>();
            path = "../Output/7-edge/sobel/vh_ct.png";
            applyFilter(input_path, filter, path);


        }
        void generateImages3D(){

            /////////// 3D

            // AIP gaussian confuciusornis 3x3x3
            // std::string input_path;
            // input_path = "../Scans/confuciusornis";
            // std::string path = "../Output/3D/Confuciusornis/aip-gaussian_3x3x3.png";
            // applyFilter3D(1, input_path, 3, 1, path, 0, 0); 
            

            // AIP gaussian confuciusornis 5x5x5
            std::string input_path = "../Scans/confuciusornis";
            std::string path = "../Output/3D/Confuciusornis/aip-gaussian_5x5x5.png";
            applyFilter3D(1, input_path, 5, 1, path, 0, 0);
            

            // AIP median confuciusornis 3x3x3
            input_path = "../Scans/confuciusornis";
            path = "../Output/3D/Confuciusornis/aip-median_3x3x3.png";
            applyFilter3D(2, input_path, 3, 1, path, 0, 0);

            // AIP median confuciusornis 5x5x5
            input_path = "../Scans/confuciusornis";
            path = "../Output/3D/Confuciusornis/aip-median_5x5x5.png";
            applyFilter3D(2, input_path, 5, 1, path, 0, 0);
            


            // MIP gaussian confuciusornis 3x3x3
            input_path = "../Scans/confuciusornis";
            path = "../Output/3D/Confuciusornis/mip-gaussian_3x3x3.png";
            applyFilter3D(1, input_path, 3, 2, path, 0, 0);


            // MIP gaussian confuciusornis 5x5x5
            input_path = "../Scans/confuciusornis";
            path = "../Output/3D/Confuciusornis/mip-gaussian_5x5x5.png";
            applyFilter3D(1, input_path, 5, 2, path, 0, 0);

            // MIP median confuciusornis 3x3x3
            input_path = "../Scans/confuciusornis";
            path = "../Output/3D/Confuciusornis/mip-median_3x3x3.png";
            applyFilter3D(2, input_path, 3, 2, path, 0, 0);
            
            // MIP median confuciusornis 5x5x5
            input_path = "../Scans/confuciusornis";
            path = "../Output/3D/Confuciusornis/mip-median_5x5x5.png";
            applyFilter3D(2, input_path, 5, 2, path, 0, 0);            

           
            //Fracture
            // MinIP gaussian fracture 3x3x3
            input_path = "../Scans/fracture";
            path = "../Output/3D/Fracture/minip-gaussian_3x3x3.png";
            applyFilter3D(1, input_path, 3, 3, path, 0, 0);
            
            // MinIP gaussian fracture 5x5x5
            input_path = "../Scans/fracture";
            path = "../Output/3D/Fracture/minip-gaussian_5x5x5.png";
            applyFilter3D(1, input_path, 5, 3, path, 0, 0);
            
            // MinIP median fracture 3x3x3
            input_path = "../Scans/fracture";
            path = "../Output/3D/Fracture/minip-median_3x3x3.png";
            applyFilter3D(2, input_path, 3, 3, path, 0, 0);
            

            // MinIP median fracture 5x5x5
            input_path = "../Scans/fracture";
            path = "../Output/3D/Fracture/minip-median_5x5x5.png";
            applyFilter3D(2, input_path, 5, 3, path, 0, 0);
            
            




            // MIP gaussian fracture 3x3x3
            input_path = "../Scans/fracture";
            path = "../Output/3D/Fracture/mip-gaussian_3x3x3.png";
            applyFilter3D(1, input_path, 3, 1, path, 0, 0);
            
            

            // MIP gaussian fracture 5x5x5
            input_path = "../Scans/fracture";
            path = "../Output/3D/Fracture/mip-gaussian_5x5x5.png";
            applyFilter3D(1, input_path, 5, 1, path, 0, 0);
            

            // MIP median fracture 3x3x3
            input_path = "../Scans/fracture";
            path = "../Output/3D/Fracture/mip-median_3x3x3.png";
            applyFilter3D(2, input_path, 3, 1, path, 0, 0);
            

            // MIP median fracture 5x5x5
            input_path = "../Scans/fracture";
            path = "../Output/3D/Fracture/mip-median_5x5x5.png";
            applyFilter3D(2, input_path, 5, 1, path, 0, 0);

        


     

        }
        void generateSlices()
        {
            //fracture
            // Slice y = 138
            std::string input_path = "../Scans/fracture";
            std::string path = "../Output/3D/Fracture/slice_xz_y138.png";
            getSlice(input_path, path, "xz", 138, 1);
            

            // Slice x = 275
            input_path = "../Scans/fracture";
            path = "../Output/3D/Fracture/slice_yz_x275.png";
            getSlice(input_path, path, "yz", 275, 1);

            //thinslab AIP 276-476
            input_path = "../Scans/fracture";
            path = "../Output/3D/Fracture/thinslab_276_476_nofilter_aip.png";
            applyFilter3D(0, input_path, 0, 1, path, 276, 476);
            // MIP fracture no filter
            input_path = "../Scans/fracture";
            path = "../Output/3D/Fracture/mip-nofilter.png";
            applyFilter3D(0, input_path, 0, 1, path, 0, 0);
            
            // MinIP fracture no filter
            input_path = "../Scans/fracture";
            path = "../Output/3D/Fracture/minip-nofilter.png";
            applyFilter3D(0, input_path, 0, 3, path, 0, 0);

            //thinslab MIP 276-476
            input_path = "../Scans/fracture";
            path = "../Output/3D/Fracture/thinslab_275_476_nofilter_mip.png";
            applyFilter3D(0, input_path, 0, 2, path, 276, 476);
            

            // MIP confucisornis no filter
            input_path = "../Scans/confuciusornis";
            path = "../Output/3D/Confuciusornis/mip-nofilter.png";

            applyFilter3D(0, input_path, 0, 2, path, 0, 0);
            // AIP confucisornis no filter 
            input_path = "../Scans/confuciusornis";
            path = "../Output/3D/Confuciusornis/aip-nofilter.png";
            applyFilter3D(0, input_path, 0, 1, path, 0, 0);

            // Slice y = 420
            input_path = "../Scans/confuciusornis";
            path = "../Output/3D/Confuciusornis/slice_xz_y420.png";
            getSlice(input_path, path, "xz", 420);

            // Slice x = 400
            input_path = "../Scans/confuciusornis";
            path = "../Output/3D/Confuciusornis/slice_yz_x400.png";
            getSlice(input_path, path, "yz", 400);

            // thin slab AIP confuciusornis 10-70
            input_path = "../Scans/confuciusornis";
            path = "../Output/3D/Confuciusornis/thinslab_10_70_nofilter_aip.png";
            applyFilter3D(0, input_path, 0, 1, path, 10, 70);

            //thin slab MIP confuciusornis 10-70
            input_path = "../Scans/confuciusornis";
            path = "../Output/3D/Confuciusornis/thinslab_10_70_nofilter_mip.png";
            applyFilter3D(0, input_path, 0, 2, path, 10, 70);
            
            
        }



        void applyFilter(std::string input_path, std::unique_ptr<Filter>& filter, std::string output_path)
        {
            Image image(input_path);
            unsigned char* data = image.getData();
            int width, height, channels;
            image.getDimensions(width, height, channels);
            filter -> apply(data, width, height, channels);
            image.save(output_path);
            std::cout << "Image saved to " << output_path << std::endl;


        }
        void applyFilteredge(std::string input_path, std::unique_ptr<EdgeDetectionFilter>& filter, std::string output_path)
        {
            Image image(input_path);
            unsigned char* data = image.getData();
            int width, height, channels;
            image.getDimensions(width, height, channels);
            filter -> apply(data, width, height, 3);
            image.save(output_path);
            std::cout << "Image saved to " << output_path << std::endl;
        }
        
        void applyFilter3D(int filterType, std::string input_path, int kernel, int option, std::string output_path, int in_slice, int out_slice) {
            Volume volume;

            volume.loadFromFolder(input_path);
            std::unique_ptr<Filter3D> filter;

            switch (filterType) {
                case 0:{
                    break;
                }
                case 1: { // 3D Gaussian Filter
                    filter = std::make_unique<Gaussian3DFilter>(kernel);
                    break;
                }
                case 2: { // 3D Median Filter - Placeholder
                    filter = std::make_unique<Median3DFilter>(kernel); // Placeholder for future functionality
                    break;
                }
                default:
                    std::cerr << "Invalid 3D filter type provided." << std::endl;
                    return;
            }

            if (filter) {
                filter->apply(volume);
                std::cout << "3D Filter applied successfully." << std::endl;
                return;
            }



            // Projections
            int width, height, depth;

            volume.getDimensions(width, height, depth);
            if (out_slice ==0)
            {
                out_slice= depth;

            }

            std::vector<unsigned char> output ;
            switch (option){
                case 1:
                    output = Projections::AIP(volume, in_slice, out_slice);
                    break;

                case 2:
                    output = Projections::MIP(volume, in_slice, out_slice);
                    break;
                case 3:
                    output = Projections::MinIP(volume, in_slice, out_slice);
                    break;
            }

            stbi_write_png(output_path.c_str(), width, height, 3, output.data(), width * 3);
        }
        void getSlice(std::string input_path, std::string output_path, std::string orientation, int slice, int channels = 3) {
            Volume volume;
            volume.loadFromFolder(input_path);

            int width, height, depth;
            volume.getDimensions(width, height, depth);

            std::vector<unsigned char> output = Slice::fromVolume(volume, orientation, slice).getData();
            stbi_write_png(output_path.c_str(), width, height, channels, output.data(), width * channels);
        }

};
