; ModuleID = 'ass2tst.c'
source_filename = "ass2tst.c"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

%struct.SS = type { i32, i32 }

; Function Attrs: noinline nounwind uwtable
define i32 @main() #0 !dbg !8 {
  %1 = alloca i32, align 4
  %2 = alloca i32*, align 8
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  %5 = alloca %struct.SS*, align 8
  store i32 0, i32* %1, align 4
  call void @llvm.dbg.declare(metadata i32** %2, metadata !17, metadata !18), !dbg !19
  call void @llvm.dbg.declare(metadata i32* %3, metadata !20, metadata !18), !dbg !21
  call void @llvm.dbg.declare(metadata i32* %4, metadata !22, metadata !18), !dbg !23
  call void @llvm.dbg.declare(metadata %struct.SS** %5, metadata !24, metadata !18), !dbg !25
  %6 = call noalias i8* @malloc(i64 40) #3, !dbg !26
  %7 = bitcast i8* %6 to i32*, !dbg !27
  store i32* %7, i32** %2, align 8, !dbg !28
  %8 = load i32*, i32** %2, align 8, !dbg !29
  %9 = getelementptr inbounds i32, i32* %8, i64 4, !dbg !29
  %10 = load i32, i32* %9, align 4, !dbg !29
  %11 = add nsw i32 %10, 1, !dbg !30
  %12 = load i32*, i32** %2, align 8, !dbg !31
  %13 = getelementptr inbounds i32, i32* %12, i64 5, !dbg !31
  store i32 %11, i32* %13, align 4, !dbg !32
  %14 = call noalias i8* @malloc(i64 8) #3, !dbg !33
  %15 = bitcast i8* %14 to %struct.SS*, !dbg !34
  store %struct.SS* %15, %struct.SS** %5, align 8, !dbg !35
  %16 = load %struct.SS*, %struct.SS** %5, align 8, !dbg !36
  %17 = getelementptr inbounds %struct.SS, %struct.SS* %16, i32 0, i32 0, !dbg !37
  %18 = load i32, i32* %17, align 4, !dbg !37
  store i32 %18, i32* %4, align 4, !dbg !38
  ret i32 0, !dbg !39
}

; Function Attrs: nounwind readnone
declare void @llvm.dbg.declare(metadata, metadata, metadata) #1

; Function Attrs: nounwind
declare noalias i8* @malloc(i64) #2

attributes #0 = { noinline nounwind uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind readnone }
attributes #2 = { nounwind "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { nounwind }

!llvm.dbg.cu = !{!0}
!llvm.module.flags = !{!14, !15}
!llvm.ident = !{!16}

!0 = distinct !DICompileUnit(language: DW_LANG_C99, file: !1, producer: "clang version 4.0.1 (https://github.com/llvm-mirror/clang.git 3c8961bedc65c9a15cbe67a2ef385a0938f7cfef) (https://github.com/llvm-mirror/llvm.git c8fccc53ed66d505898f8850bcc690c977a7c9a7)", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, enums: !2, retainedTypes: !3)
!1 = !DIFile(filename: "ass2tst.c", directory: "/gpfs/home/dbasu/llvm/lib/Transforms")
!2 = !{}
!3 = !{!4, !6}
!4 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !5, size: 64)
!5 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!6 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !7, size: 64)
!7 = distinct !DICompositeType(tag: DW_TAG_structure_type, name: "SS", scope: !8, file: !1, line: 10, size: 64, elements: !11)
!8 = distinct !DISubprogram(name: "main", scope: !1, file: !1, line: 4, type: !9, isLocal: false, isDefinition: true, scopeLine: 5, isOptimized: false, unit: !0, variables: !2)
!9 = !DISubroutineType(types: !10)
!10 = !{!5}
!11 = !{!12, !13}
!12 = !DIDerivedType(tag: DW_TAG_member, name: "ID", scope: !7, file: !1, line: 11, baseType: !5, size: 32)
!13 = !DIDerivedType(tag: DW_TAG_member, name: "age", scope: !7, file: !1, line: 12, baseType: !5, size: 32, offset: 32)
!14 = !{i32 2, !"Dwarf Version", i32 4}
!15 = !{i32 2, !"Debug Info Version", i32 3}
!16 = !{!"clang version 4.0.1 (https://github.com/llvm-mirror/clang.git 3c8961bedc65c9a15cbe67a2ef385a0938f7cfef) (https://github.com/llvm-mirror/llvm.git c8fccc53ed66d505898f8850bcc690c977a7c9a7)"}
!17 = !DILocalVariable(name: "a", scope: !8, file: !1, line: 6, type: !4)
!18 = !DIExpression()
!19 = !DILocation(line: 6, column: 8, scope: !8)
!20 = !DILocalVariable(name: "i", scope: !8, file: !1, line: 8, type: !5)
!21 = !DILocation(line: 8, column: 21, scope: !8)
!22 = !DILocalVariable(name: "c", scope: !8, file: !1, line: 8, type: !5)
!23 = !DILocation(line: 8, column: 23, scope: !8)
!24 = !DILocalVariable(name: "b", scope: !8, file: !1, line: 15, type: !6)
!25 = !DILocation(line: 15, column: 28, scope: !8)
!26 = !DILocation(line: 17, column: 27, scope: !8)
!27 = !DILocation(line: 17, column: 21, scope: !8)
!28 = !DILocation(line: 17, column: 19, scope: !8)
!29 = !DILocation(line: 28, column: 24, scope: !8)
!30 = !DILocation(line: 28, column: 29, scope: !8)
!31 = !DILocation(line: 28, column: 17, scope: !8)
!32 = !DILocation(line: 28, column: 22, scope: !8)
!33 = !DILocation(line: 38, column: 34, scope: !8)
!34 = !DILocation(line: 38, column: 21, scope: !8)
!35 = !DILocation(line: 38, column: 19, scope: !8)
!36 = !DILocation(line: 41, column: 21, scope: !8)
!37 = !DILocation(line: 41, column: 24, scope: !8)
!38 = !DILocation(line: 41, column: 19, scope: !8)
!39 = !DILocation(line: 46, column: 3, scope: !8)
