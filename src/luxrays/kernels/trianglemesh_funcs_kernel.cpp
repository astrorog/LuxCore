#include <string>
namespace luxrays { namespace ocl {
std::string KernelSource_trianglemesh_funcs = 
"#line 2 \"trianglemesh_funcs.cl\"\n"
"\n"
"/***************************************************************************\n"
" * Copyright 1998-2013 by authors (see AUTHORS.txt)                        *\n"
" *                                                                         *\n"
" *   This file is part of LuxRender.                                       *\n"
" *                                                                         *\n"
" * Licensed under the Apache License, Version 2.0 (the \"License\");         *\n"
" * you may not use this file except in compliance with the License.        *\n"
" * You may obtain a copy of the License at                                 *\n"
" *                                                                         *\n"
" *     http://www.apache.org/licenses/LICENSE-2.0                          *\n"
" *                                                                         *\n"
" * Unless required by applicable law or agreed to in writing, software     *\n"
" * distributed under the License is distributed on an \"AS IS\" BASIS,       *\n"
" * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.*\n"
" * See the License for the specific language governing permissions and     *\n"
" * limitations under the License.                                          *\n"
" ***************************************************************************/\n"
"\n"
"float3 Mesh_GetGeometryNormal(__global Point *vertices,\n"
"		__global Triangle *triangles, const uint triIndex) {\n"
"	__global Triangle *tri = &triangles[triIndex];\n"
"	const float3 p0 = VLOAD3F(&vertices[tri->v[0]].x);\n"
"	const float3 p1 = VLOAD3F(&vertices[tri->v[1]].x);\n"
"	const float3 p2 = VLOAD3F(&vertices[tri->v[2]].x);\n"
"\n"
"	return Triangle_GetGeometryNormal(p0, p1, p2);\n"
"}\n"
"\n"
"float3 Mesh_InterpolateNormal(__global Vector *normals, __global Triangle *triangles,\n"
"		const uint triIndex, const float b1, const float b2) {\n"
"	__global Triangle *tri = &triangles[triIndex];\n"
"	const float3 n0 = VLOAD3F(&normals[tri->v[0]].x);\n"
"	const float3 n1 = VLOAD3F(&normals[tri->v[1]].x);\n"
"	const float3 n2 = VLOAD3F(&normals[tri->v[2]].x);\n"
"\n"
"	const float b0 = 1.f - b1 - b2;\n"
"	return Triangle_InterpolateNormal(n0, n1, n2, b0, b1, b2);\n"
"}\n"
"\n"
"float2 Mesh_InterpolateUV(__global UV *vertUVs, __global Triangle *triangles,\n"
"		const uint triIndex, const float b1, const float b2) {\n"
"	__global Triangle *tri = &triangles[triIndex];\n"
"	const float2 uv0 = VLOAD2F(&vertUVs[tri->v[0]].u);\n"
"	const float2 uv1 = VLOAD2F(&vertUVs[tri->v[1]].u);\n"
"	const float2 uv2 = VLOAD2F(&vertUVs[tri->v[2]].u);\n"
"\n"
"	const float b0 = 1.f - b1 - b2;\n"
"	return Triangle_InterpolateUV(uv0, uv1, uv2, b0, b1, b2);\n"
"}\n"
"\n"
"float3 Mesh_InterpolateColor(__global Spectrum *vertCols, __global Triangle *triangles,\n"
"		const uint triIndex, const float b1, const float b2) {\n"
"	__global Triangle *tri = &triangles[triIndex];\n"
"	const float3 rgb0 = VLOAD3F(vertCols[tri->v[0]].c);\n"
"	const float3 rgb1 = VLOAD3F(vertCols[tri->v[1]].c);\n"
"	const float3 rgb2 = VLOAD3F(vertCols[tri->v[2]].c);\n"
"\n"
"	const float b0 = 1.f - b1 - b2;\n"
"	return Triangle_InterpolateColor(rgb0, rgb1, rgb2, b0, b1, b2);\n"
"}\n"
"\n"
"float Mesh_InterpolateAlpha(__global float *vertAlphas, __global Triangle *triangles,\n"
"		const uint triIndex, const float b1, const float b2) {\n"
"	__global Triangle *tri = &triangles[triIndex];\n"
"	const float a0 = vertAlphas[tri->v[0]];\n"
"	const float a1 = vertAlphas[tri->v[1]];\n"
"	const float a2 = vertAlphas[tri->v[2]];\n"
"\n"
"	const float b0 = 1.f - b1 - b2;\n"
"	return Triangle_InterpolateAlpha(a0, a1, a2, b0, b1, b2);\n"
"}\n"
; } }
