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
	Eigen::MatrixXd F;
	Eigen::MatrixXd Px;
	Eigen::MatrixXd Py;
	Eigen::MatrixXd R;
	void calculate(Eigen::MatrixXd Znext, Eigen::MatrixXd Z, Eigen::MatrixXd &P)
	{
		Eigen::MatrixXd X = F*Z;
		P = F*P*F.transpose();
		Eigen::MatrixXd K = P*((P + R).inverse());
		Eigen::MatrixXd X_ = X + K*(Znext - X);
		Eigen::MatrixXd P_ = P - K*P;
		std::cout << "Position: " << X_(0,0) << std::endl;
		std::cout << "Velocity: " << X_(1,0) << std::endl;
		std::cout << "Uncertainty Matrix:\n";
		std::cout << P_ << std::endl;
	}
public:
	Localization(char *DataFile)
	{
		std::cout << "Enter the timestep: ";
		std::cin >> dt;
		float x,y;
		std::cout << "Enter the initial coordinates: ";
		std::cin >> x >> y;
		F.resize(2,2);
		F(0,0) = 1; F(0,1) = dt,
		F(1,0) = 0; F(1,1) = 1;
		Px.resize(2,2);
		Px(0,0) = 1000; Px(0,1) = 0,
		Px(1,0) = 0; Px(1,1) = 1000;
		Py = Px;
		R.resize(2,2);
		R(0,0) = 0.1; R(0,1) = 0,
		R(1,0) = 0; R(1,1) = 0.1;
		std::ifstream data(DataFile);
		float in;
		while(data >> in)
		{
			float x1 = in;
			data >> in;
			float y1 = in;
			Eigen::MatrixXd tempZx(2,1);
			Eigen::MatrixXd tempZy(2,1);
			tempZx(0,0) = x1;
			tempZx(1,0) = (x1-x)/dt;
			tempZy(0,0) = y1;
			tempZy(1,0) = (y1-y)/dt;
			Zx.push_back(tempZx);
			Zy.push_back(tempZy);
			x = x1;
			y = y1;
		}
	}
	void predict()
	{
		for(int i = 1; i < Zx.size(); ++i)
		{
			std::cout << "\n\nx-axis\n";
			calculate(Zx[i], Zx[i-1], Px);
			std::cout << "\ny-axis\n";
			calculate(Zy[i], Zy[i-1], Py);
		}
	}
};