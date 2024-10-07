#include "Point.hpp"

int	main(void)
{
	//triangle's points
	Point	a(1, 1);
	Point	b(4, 1);
	Point	c(2, 5);

	//In the triangle
	// Point m(2, 2);
	// Point n(3.99, 1.01);
	// Point p(2.5, 2);

	//Out of the triangle
	// Point q(0, 0);
	// Point r(5, 6);
	// Point s(3, 0);
	// Point t(2, 6);

	//On triangle's points
	// Point u(1, 1);
	// Point v(4, 1);
	// Point w(2, 5);

	//On triangle's edges
	// Point x(3.5, 2);
	// Point y(1.5,3);
	// Point z(3, 3);

	std::cout << "Pour le point M BSP retourne : " << bsp(Point(1, 1), Point(4, 1), Point(2, 5), Point(2, 2)) << std::endl;
	std::cout << "Pour le point N BSP retourne : " << bsp(Point(1, 1), Point(4, 1), Point(2, 5), Point(3.99,1.01)) << std::endl;
	std::cout << "Pour le point P BSP retourne : " << bsp(Point(1, 1), Point(4, 1), Point(2, 5), Point(2.5, 2)) << std::endl;

	std::cout << "Pour le point Q BSP retourne : " << bsp(Point(1, 1), Point(4, 1), Point(2, 5), Point(0, 0)) << std::endl;
	std::cout << "Pour le point R BSP retourne : " << bsp(Point(1, 1), Point(4, 1), Point(2, 5), Point(5, 6)) << std::endl;
	std::cout << "Pour le point S BSP retourne : " << bsp(Point(1, 1), Point(4, 1), Point(2, 5), Point(3, 0)) << std::endl;
	std::cout << "Pour le point T BSP retourne : " << bsp(Point(1, 1), Point(4, 1), Point(2, 5), Point(2, 6)) << std::endl;

	std::cout << "Pour le point U BSP retourne : " << bsp(Point(1, 1), Point(4, 1), Point(2, 5), Point(1, 1)) << std::endl;
	std::cout << "Pour le point V BSP retourne : " << bsp(Point(1, 1), Point(4, 1), Point(2, 5), Point(4, 1)) << std::endl;
	std::cout << "Pour le point W BSP retourne : " << bsp(Point(1, 1), Point(4, 1), Point(2, 5), Point(2, 5)) << std::endl;

	std::cout << "Pour le point X BSP retourne : " << bsp(Point(1, 1), Point(4, 1), Point(2, 5), Point(3.5, 2)) << std::endl;
	std::cout << "Pour le point Y BSP retourne : " << bsp(Point(1, 1), Point(4, 1), Point(2, 5), Point(1.5,3)) << std::endl;
	std::cout << "Pour le point Z BSP retourne : " << bsp(Point(1, 1), Point(4, 1), Point(2, 5), Point(3, 3)) << std::endl;


	return (0);
}