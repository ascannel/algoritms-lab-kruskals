#include "pch.h"
#include "../kruskalsHeader.hpp"
#include <chrono>

TEST(kruskalMSTWithoutPathCompression, threeDotOneA) {
    std::ofstream output_file("../../times/WithoutPathCompression3Dot1ATimes.txt");
    for (int n = 1; n <= 10001; n += 100) {
        int m = (n * n) / 10; // m = (n^2)/10 
        auto edges = generateRandomGraph(n, m, 1, 1000000);

        auto start = std::chrono::high_resolution_clock::now();
        auto mst = kruskalMST(edges, n, false);
        auto end = std::chrono::high_resolution_clock::now();
        double elapsedTimeMs = std::chrono::duration<double, std::milli>(end - start).count();
        std::cout << "execution time without compression for n = " << n << ", m = " << m << ": " << elapsedTimeMs << " ms" << std::endl;
        if (output_file.is_open()) {
                output_file << n << ", " << m << ": " << elapsedTimeMs << " ms"<< std::endl;
        }
        else {
            std::cerr << "unable to open output file" << std::endl;
        }
        EXPECT_EQ(mst.size(), n - 1);
    }
    output_file.close();
}

TEST(kruskalMSTWithoutPathCompression, threeDotOneB) {
    std::ofstream output_file("../../times/WithoutPathCompression3Dot1BTimes.txt");
    for (int n = 1; n <= 10001; n += 100) {
        int m = (n * n); // m = (n^2) 
        auto edges = generateRandomGraph(n, m, 1, 1000000);

        auto start = std::chrono::high_resolution_clock::now();
        auto mst = kruskalMST(edges, n, false);
        auto end = std::chrono::high_resolution_clock::now();
        double elapsedTimeMs = std::chrono::duration<double, std::milli>(end - start).count();
        std::cout << "execution time without compression for n = " << n << ", m = " << m << ": " << elapsedTimeMs << " ms" << std::endl;
        if (output_file.is_open()) {
            output_file << n << ", " << m << ": " << elapsedTimeMs << " ms" << std::endl;
        }
        else {
            std::cerr << "unable to open output file" << std::endl;
        }
        EXPECT_EQ(mst.size(), n - 1);
    }
    output_file.close();
}

TEST(kruskalMSTWithoutPathCompression, threeDotTwoA) {
    std::ofstream output_file("../../times/WithoutPathCompression3Dot2ATimes.txt");
    for (int n = 1; n <= 10001; n += 100) {
        int m = 100 * n; // m = 100n  
        auto edges = generateRandomGraph(n, m, 1, 1000000);

        auto start = std::chrono::high_resolution_clock::now();
        auto mst = kruskalMST(edges, n, false);
        auto end = std::chrono::high_resolution_clock::now();
        double elapsedTimeMs = std::chrono::duration<double, std::milli>(end - start).count();
        std::cout << "execution time without compression for n = " << n << ", m = " << m << ": " << elapsedTimeMs << " ms" << std::endl;
        if (output_file.is_open()) {
            output_file << n << ", " << m << ": " << elapsedTimeMs << " ms" << std::endl;
        }
        else {
            std::cerr << "unable to open output file" << std::endl;
        }
        EXPECT_EQ(mst.size(), n - 1);
    }
    output_file.close();
}

TEST(kruskalMSTWithoutPathCompression, threeDotTwoB) {
    std::ofstream output_file("../../times/WithoutPathCompression3Dot2BTimes.txt");
    for (int n = 1; n <= 10001; n += 100) {
        int m = 1000 * n; // m = 1000n
        auto edges = generateRandomGraph(n, m, 1, 1000000);

        auto start = std::chrono::high_resolution_clock::now();
        auto mst = kruskalMST(edges, n, false);
        auto end = std::chrono::high_resolution_clock::now();
        double elapsedTimeMs = std::chrono::duration<double, std::milli>(end - start).count();
        std::cout << "execution time without compression for n = " << n << ", m = " << m << ": " << elapsedTimeMs << " ms" << std::endl;
        if (output_file.is_open()) {
            output_file << n << ", " << m << ": " << elapsedTimeMs << " ms" << std::endl;
        }
        else {
            std::cerr << "unable to open output file" << std::endl;
        }
        EXPECT_EQ(mst.size(), n - 1);
    }
    output_file.close();
}

TEST(kruskalMSTWithoutPathCompression, threeDotThree) {
    std::ofstream output_file("../../times/WithoutPathCompression3Dot3Times.txt");
    for (int m = 0; m <= 10000000; m += 100000) {
        int n = 10001;
        auto edges = generateRandomGraph(n, m, 1, 1000000);

        auto start = std::chrono::high_resolution_clock::now();
        auto mst = kruskalMST(edges, n, false);
        auto end = std::chrono::high_resolution_clock::now();
        double elapsedTimeMs = std::chrono::duration<double, std::milli>(end - start).count();
        std::cout << "execution time without compression for n = " << n << ", m = " << m << ": " << elapsedTimeMs << " ms" << std::endl;
        if (output_file.is_open()) {
            output_file << n << ", " << m << ": " << elapsedTimeMs << " ms" << std::endl;
        }
        else {
            std::cerr << "unable to open output file" << std::endl;
        }
        EXPECT_EQ(mst.size(), n - 1);
    }
    output_file.close();
}

TEST(kruskalMSTWithoutPathCompression, threeDotFourA) {
    std::ofstream output_file("../../times/WithoutPathCompression3Dot4ATimes.txt");
    for (int r = 1; r <= 200; r += 1) {
        int n = 10001;
        int m = (n * n); // m = n^2
        auto edges = generateRandomGraph(n, m, 1, r);

        auto start = std::chrono::high_resolution_clock::now();
        auto mst = kruskalMST(edges, n, false);
        auto end = std::chrono::high_resolution_clock::now();
        double elapsedTimeMs = std::chrono::duration<double, std::milli>(end - start).count();
        std::cout << "execution time without compression for n = " << n << ", m = " << m << ": " << elapsedTimeMs << " ms" << std::endl;
        if (output_file.is_open()) {
            output_file << m << ", " << r << ": " << elapsedTimeMs << " ms" << std::endl;
        }
        else {
            std::cerr << "unable to open output file" << std::endl;
        }
        EXPECT_EQ(mst.size(), n - 1);
    }
    output_file.close();
}

TEST(kruskalMSTWithoutPathCompression, threeDotFourB) {
    std::ofstream output_file("../../times/WithoutPathCompression3Dot4BTimes.txt");
    for (int r = 1; r <= 200; r += 1) {
        int n = 10001;
        int m = 1000 * n; // m = 1000n
        auto edges = generateRandomGraph(n, m, 1, r);

        auto start = std::chrono::high_resolution_clock::now();
        auto mst = kruskalMST(edges, n, false);
        auto end = std::chrono::high_resolution_clock::now();
        double elapsedTimeMs = std::chrono::duration<double, std::milli>(end - start).count();
        std::cout << "execution time without compression for n = " << n << ", m = " << m << ": " << elapsedTimeMs << " ms" << std::endl;
        if (output_file.is_open()) {
            output_file << m << ", " << r << ": " << elapsedTimeMs << " ms" << std::endl;
        }
        else {
            std::cerr << "unable to open output file" << std::endl;
        }
        EXPECT_EQ(mst.size(), n - 1);
    }
    output_file.close();
}

TEST(kruskalMSTWithPathCompression, threeDotOneA) {
    std::ofstream output_file("../../times/WithPathCompression3Dot1ATimes.txt");
    for (int n = 1; n <= 10001; n += 100) {
        int m = (n * n) / 10; // m = (n^2)/10 
        auto edges = generateRandomGraph(n, m, 1, 1000000);

        auto start = std::chrono::high_resolution_clock::now();
        auto mst = kruskalMST(edges, n, true);
        auto end = std::chrono::high_resolution_clock::now();
        double elapsedTimeMs = std::chrono::duration<double, std::milli>(end - start).count();
        std::cout << "execution time with compression for n = " << n << ", m = " << m << ": " << elapsedTimeMs << " ms" << std::endl;
        if (output_file.is_open()) {
            output_file << n << ", " << m << ": " << elapsedTimeMs << " ms" << std::endl;
        }
        else {
            std::cerr << "unable to open output file" << std::endl;
        }
        EXPECT_EQ(mst.size(), n - 1);
    }
    output_file.close();
}

TEST(kruskalMSTWithPathCompression, threeDotOneB) {
    std::ofstream output_file("../../times/WithPathCompression3Dot1BTimes.txt");
    for (int n = 1; n <= 10001; n += 100) {
        int m = (n * n); // m = (n^2) 
        auto edges = generateRandomGraph(n, m, 1, 1000000);

        auto start = std::chrono::high_resolution_clock::now();
        auto mst = kruskalMST(edges, n, true);
        auto end = std::chrono::high_resolution_clock::now();
        double elapsedTimeMs = std::chrono::duration<double, std::milli>(end - start).count();
        std::cout << "execution time with compression for n = " << n << ", m = " << m << ": " << elapsedTimeMs << " ms" << std::endl;
        if (output_file.is_open()) {
            output_file << n << ", " << m << ": " << elapsedTimeMs << " ms" << std::endl;
        }
        else {
            std::cerr << "unable to open output file" << std::endl;
        }
        EXPECT_EQ(mst.size(), n - 1);
    }
    output_file.close();
}

TEST(kruskalMSTWithPathCompression, threeDotTwoA) {
    std::ofstream output_file("../../times/WithPathCompression3Dot2ATimes.txt");
    for (int n = 1; n <= 10001; n += 100) {
        int m = 100 * n; // m = 100n  
        auto edges = generateRandomGraph(n, m, 1, 1000000);

        auto start = std::chrono::high_resolution_clock::now();
        auto mst = kruskalMST(edges, n, true);
        auto end = std::chrono::high_resolution_clock::now();
        double elapsedTimeMs = std::chrono::duration<double, std::milli>(end - start).count();
        std::cout << "execution time with compression for n = " << n << ", m = " << m << ": " << elapsedTimeMs << " ms" << std::endl;
        if (output_file.is_open()) {
            output_file << n << ", " << m << ": " << elapsedTimeMs << " ms" << std::endl;
        }
        else {
            std::cerr << "unable to open output file" << std::endl;
        }
        EXPECT_EQ(mst.size(), n - 1);
    }
    output_file.close();
}

TEST(kruskalMSTWithPathCompression, threeDotTwoB) {
    std::ofstream output_file("../../times/WithPathCompression3Dot2BTimes.txt");
    for (int n = 1; n <= 10001; n += 100) {
        int m = 1000 * n; // m = 1000n
        auto edges = generateRandomGraph(n, m, 1, 1000000);

        auto start = std::chrono::high_resolution_clock::now();
        auto mst = kruskalMST(edges, n, true);
        auto end = std::chrono::high_resolution_clock::now();
        double elapsedTimeMs = std::chrono::duration<double, std::milli>(end - start).count();
        std::cout << "execution time with compression for n = " << n << ", m = " << m << ": " << elapsedTimeMs << " ms" << std::endl;
        if (output_file.is_open()) {
            output_file << n << ", " << m << ": " << elapsedTimeMs << " ms" << std::endl;
        }
        else {
            std::cerr << "unable to open output file" << std::endl;
        }
        EXPECT_EQ(mst.size(), n - 1);
    }
    output_file.close();
}

TEST(kruskalMSTWithPathCompression, threeDotThree) {
    std::ofstream output_file("../../times/WithPathCompression3Dot3Times.txt");
    for (int m = 0; m <= 10000000; m += 100000) {
        int n = 10001;
        auto edges = generateRandomGraph(n, m, 1, 1000000);

        auto start = std::chrono::high_resolution_clock::now();
        auto mst = kruskalMST(edges, n, true);
        auto end = std::chrono::high_resolution_clock::now();
        double elapsedTimeMs = std::chrono::duration<double, std::milli>(end - start).count();
        std::cout << "execution time with compression for n = " << n << ", m = " << m << ": " << elapsedTimeMs << " ms" << std::endl;
        if (output_file.is_open()) {
            output_file << n << ", " << m << ": " << elapsedTimeMs << " ms" << std::endl;
        }
        else {
            std::cerr << "unable to open output file" << std::endl;
        }
        EXPECT_EQ(mst.size(), n - 1);
    }
    output_file.close();
}

TEST(kruskalMSTWithPathCompression, threeDotFourA) {
    std::ofstream output_file("../../times/WithPathCompression3Dot4ATimes.txt");
    for (int r = 1; r <= 200; r += 1) {
        int n = 10001;
        int m = (n * n); // m = n^2
        auto edges = generateRandomGraph(n, m, 1, r);

        auto start = std::chrono::high_resolution_clock::now();
        auto mst = kruskalMST(edges, n, true);
        auto end = std::chrono::high_resolution_clock::now();
        double elapsedTimeMs = std::chrono::duration<double, std::milli>(end - start).count();
        std::cout << "execution time with compression for n = " << n << ", m = " << m << ": " << elapsedTimeMs << " ms" << std::endl;
        if (output_file.is_open()) {
            output_file << m << ", " << r << ": " << elapsedTimeMs << " ms" << std::endl;
        }
        else {
            std::cerr << "unable to open output file" << std::endl;
        }
        EXPECT_EQ(mst.size(), n - 1);
    }
    output_file.close();
}

TEST(kruskalMSTWithPathCompression, threeDotFourB) {
    std::ofstream output_file("../../times/WithPathCompression3Dot4BTimes.txt");
    for (int r = 1; r <= 200; r += 1) {
        int n = 10001;
        int m = 1000 * n; // m = 1000n
        auto edges = generateRandomGraph(n, m, 1, r);

        auto start = std::chrono::high_resolution_clock::now();
        auto mst = kruskalMST(edges, n, true);
        auto end = std::chrono::high_resolution_clock::now();
        double elapsedTimeMs = std::chrono::duration<double, std::milli>(end - start).count();
        std::cout << "execution time with compression for n = " << n << ", m = " << m << ": " << elapsedTimeMs << " ms" << std::endl;
        if (output_file.is_open()) {
            output_file << m << ", " << r << ": " << elapsedTimeMs << " ms" << std::endl;
        }
        else {
            std::cerr << "unable to open output file" << std::endl;
        }
        EXPECT_EQ(mst.size(), n - 1);
    }
    output_file.close();
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}