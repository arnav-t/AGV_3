# AGV_3
## Localization task for AGV

### Screenshots for each of the text file given.
For example, Localization_txt.png is the corresponding screenshot for Localization.txt
### Points in the text files are delimited by spaces instead of commas. 
This was only for convenience, hope that won't be a problem.
### Implementation
I've implemented the Kalman filter (in 1D) seperately for x and y as covariance between them is given to be zero. To get over the lack of any velocity readings. I calculated the velocity "readings" as         
v<sub>k</sub> = (x<sub>k</sub> - x<sub>k-1</sub>)/ΔT     
      
#### Implementation based on [Michel van Biezen's video series on Kalman Filter](https://www.youtube.com/playlist?list=PLX2gX-ftPVXU3oUFNATxGXY90AULiqnWT)

