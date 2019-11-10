// This source code is property of the Computer Graphics and Visualization 
// chair of the TU Dresden. Do not distribute! 
// Copyright (C) CGV TU Dresden - All Rights Reserved

#include "SurfaceArea.h"

#include <iostream>

float ComputeSurfaceArea(const HEMesh& m)
//float ComputeSurfaceArea(HEMesh& m)
{
	float area = 0;
	/* Task 1.2.2 */

	HEMesh mesh = m;
	
	OpenMesh::PolyConnectivity::VertexIter vIt, vBegin, vEnd;
	OpenMesh::PolyConnectivity::FaceVertexIter fv_it;

	vBegin = m.vertices_begin();
	vEnd = m.vertices_end();
	
	//Tetrahedron has 4 vertices/sides
	if (m.n_vertices() == 4) {
		for (vIt=vBegin;vIt != vEnd;++vIt) {
			
			OpenMesh::PolyConnectivity::VertexFaceIter  vfIt, vfBegin;
			vfBegin = mesh.vf_iter(vIt);

			for (vfIt = vfBegin;vfIt;++vfIt) {
				
				fv_it = mesh.fv_iter(vfIt);

				const HEMesh::Point& A = m.point(fv_it);
				++fv_it;
				const HEMesh::Point& B = m.point(fv_it);
				++fv_it;
				const HEMesh::Point& C = m.point(fv_it);

				area += ((B - A) % (C - A)).norm() * 0.5f;
			}
		}
	}
	else {
		// Calculate surface area for polygonal mesh
		for (vIt = vBegin;vIt != vEnd;++vIt) {

			OpenMesh::PolyConnectivity::VertexFaceIter  vfIt, vfBegin;
			vfBegin = mesh.vf_iter(vIt);

			// Create arbitrary point and find area for each side
			for (vfIt = vfBegin;vfIt;++vfIt) {
				fv_it = mesh.fv_iter(vfIt);
				

			}
		}
	}


	std::cout << "Area computation is not implemented." << std::endl;
	return area;
}