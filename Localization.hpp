#include <eigen3/Eigen/Dense>
#include <vector>

#define Localization_HPP

#define sigma2 1000

class Localization
{
private:
	float dt;
	std::vector<Eigen::MatrixXd> Zx;
	std::vector<Eigen::MatrixXd> Zy;
	Eigen::MatrixXd Fx(2,2);
	Eigen::MatrixXd Fy(2,2);
	Eigen::MatrixXd Px(2,2);
	Eigen::MatrixXd Py(2,2);
	Eigen::MatrixXd R(2,2);
public:
	Localization(char *DataFile)
	{
		std::cout << "Enter the timestep: ";
		std::cin >> dt;
		float x,y;
		std::cout << "Enter the initial coordinates: ";
		std::cin >> x >> y;
		ifstream data(DataFile);
		float in;
		while(data >> in)
		{
			float x1 = in;
			data >> in;
			float y1 = in;
			MatrixXd tempZx(2,1);
			MatrixXd tempZy(2,1);
			tempZx << x1,
					  (x1-x)/dt;
			tempZy << y1,
					  (y1-y)/dt;
			Zx.push_back(tempZx);
			Zy.push_back(tempZy);
			x = x1;
			y = y1;
		}
	}
};