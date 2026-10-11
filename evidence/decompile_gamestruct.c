//==== 0x140001080 {"status":"resolved","address":"0x140001080","name":"FUN_140001080"}

void FUN_140001080(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined4 *puVar1;
  
  puVar1 = FUN_140004a60(4,param_2,param_3,param_4);
  *puVar1 = 10;
  return;
}


//==== 0x1400010a0 {"status":"resolved","address":"0x1400010a0","name":"FUN_1400010a0"}

ulonglong FUN_1400010a0(uint param_1,undefined8 *param_2,undefined8 *param_3,undefined8 param_4)

{
  uint uVar1;
  undefined8 uVar2;
  uint *puVar3;
  char *pcVar4;
  undefined8 *unaff_RBX;
  ulonglong uVar5;
  undefined1 auStack_a8 [32];
  char local_88 [88];
  ulonglong local_30;
  
  local_30 = DAT_14001c000 ^ (ulonglong)auStack_a8;
  if (param_1 < 5) {
    uVar1 = *(uint *)(&DAT_1400171c0 + (longlong)(int)param_1 * 4);
    pcVar4 = "%d points";
    uVar5 = (ulonglong)uVar1;
    FUN_140001000(local_88,"%d points",uVar5,param_4);
    uVar2 = FUN_140004b20(local_88,pcVar4,uVar5,param_4);
    *param_2 = uVar2;
    puVar3 = FUN_140004a60(4,pcVar4,uVar5,param_4);
    *param_3 = puVar3;
    *puVar3 = uVar1;
    unaff_RBX = param_2;
  }
  FUN_140016090(local_30 ^ (ulonglong)auStack_a8);
  return CONCAT71((int7)((ulonglong)unaff_RBX >> 8),param_1 < 5) & 0xffffffff;
}


//==== 0x140001130 {"status":"resolved","address":"0x140001130","name":"FUN_140001130"}

void FUN_140001130(int *param_1,char *param_2)

{
  int iVar1;
  
  iVar1 = atoi(param_2);
  *param_1 = iVar1;
  return;
}


//==== 0x140001150 {"status":"resolved","address":"0x140001150","name":"FUN_140001150"}

undefined8 FUN_140001150(uint *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined *puVar2;
  ulonglong uVar3;
  undefined1 auStack_88 [32];
  char local_68 [88];
  ulonglong local_10;
  
  local_10 = DAT_14001c000 ^ (ulonglong)auStack_88;
  uVar3 = (ulonglong)*param_1;
  puVar2 = &DAT_1400182a8;
  FUN_140001000(local_68,&DAT_1400182a8,uVar3,param_4);
  uVar1 = FUN_140004b20(local_68,puVar2,uVar3,param_4);
  FUN_140016090(local_10 ^ (ulonglong)auStack_88);
  return uVar1;
}


//==== 0x1400011b0 {"status":"resolved","address":"0x1400011b0","name":"FUN_1400011b0"}

void FUN_1400011b0(void *param_1)

{
  if (param_1 != (void *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000140004aa5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    free(param_1);
    return;
  }
  return;
}


//==== 0x1400011c0 {"status":"resolved","address":"0x1400011c0","name":"FUN_1400011c0"}

void FUN_1400011c0(undefined4 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined4 *puVar1;
  
  puVar1 = FUN_140004a60(4,param_2,param_3,param_4);
  *puVar1 = *param_1;
  return;
}


//==== 0x1400011e0 {"status":"resolved","address":"0x1400011e0","name":"FUN_1400011e0"}

undefined8 * FUN_1400011e0(uint *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined *puVar3;
  ulonglong uVar4;
  undefined1 auStack_88 [32];
  char local_68 [80];
  ulonglong local_18;
  
  local_18 = DAT_14001c000 ^ (ulonglong)auStack_88;
  puVar1 = FUN_140004a60(0x90,param_2,param_3,param_4);
  *puVar1 = "Number of points";
  *(undefined4 *)(puVar1 + 2) = 0;
  uVar4 = (ulonglong)*param_1;
  puVar3 = &DAT_1400182a8;
  FUN_140001000(local_68,&DAT_1400182a8,uVar4,param_4);
  uVar2 = FUN_140004b20(local_68,puVar3,uVar4,param_4);
  puVar1[3] = uVar2;
  puVar1[6] = 0;
  *(undefined4 *)(puVar1 + 8) = 3;
  FUN_140016090(local_18 ^ (ulonglong)auStack_88);
  return puVar1;
}


//==== 0x140001260 {"status":"resolved","address":"0x140001260","name":"FUN_140001260"}

int * FUN_140001260(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = FUN_140004a60(4,param_2,param_3,param_4);
  iVar1 = atoi(*(char **)(param_1 + 0x18));
  *piVar2 = iVar1;
  return piVar2;
}


//==== 0x140001290 {"status":"unknown","error":{"code":"invalid_request","category":"invalid_input","message":"Analysis input is invalid. Check the arguments and try again.","retryable":true,"remediation":{"action":"Correct the listed arguments and retry."},"details":{"operation":"procedure_address","issues":[{"path":[],"reason":"invalid_value","message":"No procedure exists at the requested address: 0x140001290"}]}}}
{"code":"invalid_request","category":"invalid_input","message":"Analysis input is invalid. Check the arguments and try again.","retryable":true,"remediation":{"action":"Correct the listed arguments and retry."},"details":{"operation":"procedure_pseudo_code","issues":[{"path":[],"reason":"invalid_value","message":"No procedure exists at the requested address: 0x140001290"}]}}
//==== 0x1400012c0 {"status":"resolved","address":"0x1400012c0","name":"FUN_1400012c0"}

void * FUN_1400012c0(uint *param_1,int *param_2,undefined8 *param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  size_t sVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  void *pvVar10;
  undefined4 *puVar11;
  longlong *plVar12;
  longlong *plVar13;
  int *piVar14;
  longlong lVar15;
  undefined8 uVar16;
  uint *puVar17;
  void *pvVar18;
  wchar_t *_NumOfElements;
  uint *puVar19;
  void *pvVar20;
  ulonglong *puVar21;
  int iVar22;
  ulonglong uVar23;
  undefined4 *puVar24;
  ulonglong uVar25;
  char *pcVar26;
  undefined4 *_NumOfElements_00;
  longlong lVar27;
  uint uVar28;
  ulonglong uVar29;
  ulonglong uVar30;
  undefined4 *puVar31;
  longlong lVar32;
  int *piVar33;
  undefined *puVar34;
  int *piVar35;
  int *piVar36;
  undefined1 *puVar37;
  uint uVar38;
  longlong lVar39;
  double dVar40;
  int iVar41;
  int iVar42;
  double dVar43;
  undefined1 auStack_238 [32];
  uint local_218;
  uint local_210;
  byte local_1f9;
  longlong *local_1f8;
  ulonglong local_1f0;
  void *local_1e8;
  ulonglong *local_1e0;
  uint local_1d8;
  uint local_1d4;
  void *local_1d0;
  longlong *local_1c8;
  ulonglong local_1c0;
  size_t local_1b8;
  undefined8 *local_1b0;
  undefined4 *local_1a8;
  longlong local_1a0;
  int local_194;
  int *local_190;
  size_t local_188;
  longlong local_180;
  undefined4 *local_178;
  undefined4 *local_170;
  undefined4 *local_168;
  longlong local_160;
  undefined8 local_158;
  undefined4 local_150;
  undefined8 local_148;
  undefined4 local_140;
  undefined8 local_138;
  int local_130;
  undefined8 local_128;
  undefined4 local_120;
  ulonglong local_d0;
  
  local_d0 = DAT_14001c000 ^ (ulonglong)auStack_238;
  uVar28 = *param_1;
  lVar32 = (longlong)(int)uVar28;
  uVar30 = (ulonglong)uVar28;
  local_1b0 = param_3;
  local_190 = param_2;
  iVar6 = FUN_140003f30(uVar28 * 3);
  local_188 = lVar32 * 4;
  local_1b8 = lVar32 * 0xc;
  local_1a0 = lVar32;
  local_1e0 = FUN_140004a60(local_1b8,param_2,param_3,param_4);
  uVar38 = iVar6 * iVar6;
  puVar24 = (undefined4 *)(ulonglong)uVar38;
  pvVar10 = FUN_140004a60((longlong)puVar24 * 4,param_2,param_3,param_4);
  if (uVar38 != 0) {
    if (uVar38 < 8) {
      puVar11 = (undefined4 *)0x0;
    }
    else {
      puVar11 = (undefined4 *)(ulonglong)(uVar38 & 0x7ffffff8);
      uVar23 = ((ulonglong)(puVar11 + -2) >> 3) + 1;
      uVar29 = (ulonglong)((uint)uVar23 & 3);
      if (puVar11 + -2 < (undefined4 *)0x18) {
        iVar22 = 0;
        iVar9 = 1;
        iVar42 = 2;
        iVar41 = 3;
        lVar32 = 0;
      }
      else {
        uVar23 = uVar23 & 0xfffffffffffffffc;
        iVar22 = 0;
        iVar9 = 1;
        iVar42 = 2;
        iVar41 = 3;
        lVar32 = 0;
        do {
          piVar33 = (int *)((longlong)pvVar10 + lVar32 * 4);
          *piVar33 = iVar22;
          piVar33[1] = iVar9;
          piVar33[2] = iVar42;
          piVar33[3] = iVar41;
          piVar33 = (int *)((longlong)pvVar10 + lVar32 * 4 + 0x10);
          *piVar33 = iVar22 + 4;
          piVar33[1] = iVar9 + 4;
          piVar33[2] = iVar42 + 4;
          piVar33[3] = iVar41 + 4;
          piVar33 = (int *)((longlong)pvVar10 + lVar32 * 4 + 0x20);
          *piVar33 = iVar22 + 8;
          piVar33[1] = iVar9 + 8;
          piVar33[2] = iVar42 + 8;
          piVar33[3] = iVar41 + 8;
          piVar33 = (int *)((longlong)pvVar10 + lVar32 * 4 + 0x30);
          *piVar33 = iVar22 + 0xc;
          piVar33[1] = iVar9 + 0xc;
          piVar33[2] = iVar42 + 0xc;
          piVar33[3] = iVar41 + 0xc;
          piVar33 = (int *)((longlong)pvVar10 + lVar32 * 4 + 0x40);
          *piVar33 = iVar22 + 0x10;
          piVar33[1] = iVar9 + 0x10;
          piVar33[2] = iVar42 + 0x10;
          piVar33[3] = iVar41 + 0x10;
          piVar33 = (int *)((longlong)pvVar10 + lVar32 * 4 + 0x50);
          *piVar33 = iVar22 + 0x14;
          piVar33[1] = iVar9 + 0x14;
          piVar33[2] = iVar42 + 0x14;
          piVar33[3] = iVar41 + 0x14;
          piVar33 = (int *)((longlong)pvVar10 + lVar32 * 4 + 0x60);
          *piVar33 = iVar22 + 0x18;
          piVar33[1] = iVar9 + 0x18;
          piVar33[2] = iVar42 + 0x18;
          piVar33[3] = iVar41 + 0x18;
          piVar33 = (int *)((longlong)pvVar10 + lVar32 * 4 + 0x70);
          *piVar33 = iVar22 + 0x1c;
          piVar33[1] = iVar9 + 0x1c;
          piVar33[2] = iVar42 + 0x1c;
          piVar33[3] = iVar41 + 0x1c;
          lVar32 = lVar32 + 0x20;
          iVar22 = iVar22 + 0x20;
          iVar9 = iVar9 + 0x20;
          iVar42 = iVar42 + 0x20;
          iVar41 = iVar41 + 0x20;
          uVar23 = uVar23 - 4;
        } while (uVar23 != 0);
      }
      if (uVar29 != 0) {
        lVar39 = 0;
        do {
          piVar33 = (int *)((longlong)pvVar10 + lVar39 + lVar32 * 4);
          *piVar33 = iVar22;
          piVar33[1] = iVar9;
          piVar33[2] = iVar42;
          piVar33[3] = iVar41;
          piVar33 = (int *)((longlong)pvVar10 + lVar39 + lVar32 * 4 + 0x10);
          *piVar33 = iVar22 + 4;
          piVar33[1] = iVar9 + 4;
          piVar33[2] = iVar42 + 4;
          piVar33[3] = iVar41 + 4;
          iVar22 = iVar22 + 8;
          iVar9 = iVar9 + 8;
          iVar42 = iVar42 + 8;
          iVar41 = iVar41 + 8;
          lVar39 = lVar39 + 0x20;
        } while (uVar29 << 5 != lVar39);
      }
      if (puVar11 == puVar24) goto LAB_14000150c;
    }
    do {
      *(int *)((longlong)pvVar10 + (longlong)puVar11 * 4) = (int)puVar11;
      puVar11 = (undefined4 *)((longlong)puVar11 + 1);
    } while (puVar24 != puVar11);
  }
LAB_14000150c:
  piVar33 = (int *)0x4;
  piVar35 = local_190;
  FUN_140005430((longlong)pvVar10,uVar38,4,(char *)local_190);
  if (0 < (int)uVar28) {
    puVar21 = local_1e0 + 1;
    uVar29 = 0;
    do {
      *(int *)(puVar21 + -1) = *(int *)((longlong)pvVar10 + uVar29 * 4) % iVar6;
      iVar22 = *(int *)((longlong)pvVar10 + uVar29 * 4);
      puVar24 = (undefined4 *)((longlong)iVar22 % (longlong)iVar6 & 0xffffffff);
      *(int *)((longlong)puVar21 + -4) = iVar22 / iVar6;
      *(undefined4 *)puVar21 = 1;
      uVar29 = uVar29 + 1;
      puVar21 = (ulonglong *)((longlong)puVar21 + 0xc);
    } while (uVar30 != uVar29);
  }
  local_194 = iVar6;
  FUN_140004aa0(pvVar10);
  sVar2 = local_1a0 * 8;
  local_1a8 = FUN_140004a60(sVar2,puVar24,piVar33,piVar35);
  plVar12 = (longlong *)FUN_1400056e0(&LAB_140004140,puVar24,piVar33,piVar35);
  if (0 < (int)uVar28) {
    uVar29 = 0;
    puVar11 = local_1a8;
    do {
      *puVar11 = 0;
      puVar11[1] = (int)uVar29;
      puVar24 = puVar11;
      FUN_1400057c0(plVar12,(longlong)puVar11,piVar33,piVar35);
      uVar29 = uVar29 + 1;
      puVar11 = puVar11 + 2;
    } while (uVar30 != uVar29);
  }
  plVar13 = (longlong *)FUN_1400056e0(&LAB_140004140,puVar24,piVar33,piVar35);
  local_1d0 = FUN_140004a60(sVar2,puVar24,piVar33,piVar35);
  uVar29 = 0;
  local_1d4 = 0;
  if (0 < (int)uVar28) {
    local_1d4 = uVar28;
  }
  local_180 = uVar30 * 0xc;
  puVar11 = (undefined4 *)0x0;
  local_1f8 = plVar13;
  local_1f0 = uVar30;
  local_1c8 = plVar12;
LAB_140001660:
  do {
    uVar23 = uVar29;
    if ((uint)puVar11 != local_1d4) {
LAB_14000166b:
      while( true ) {
        local_1c0 = uVar29;
        puVar24 = puVar11;
        iVar6 = (int)puVar24;
        piVar14 = (int *)FUN_1400059b0(plVar12,iVar6);
        uVar23 = local_1c0;
        if (3 < *piVar14) break;
        uVar28 = iVar6 + 1;
        puVar11 = (undefined4 *)(ulonglong)uVar28;
        if ((int)uVar28 < (int)uVar30) {
          uVar38 = piVar14[1];
          lVar39 = (longlong)(int)uVar38;
          piVar14 = (int *)((longlong)local_1e0 + lVar39 * 0xc);
          puVar31 = (undefined4 *)0x0;
          lVar32 = local_1a0;
          local_1d8 = uVar28;
          do {
            piVar33 = (int *)FUN_1400059b0(plVar12,(int)puVar11);
            if (*piVar33 < 4) {
              uVar28 = piVar33[1];
              if (uVar28 == uVar38) {
                _wassert(L"a != b",L"/puzzles/untangle.c",0x1e8);
              }
              uVar7 = uVar38;
              if ((int)uVar28 < (int)uVar38) {
                uVar7 = uVar28;
              }
              uVar8 = uVar38;
              if ((int)uVar38 < (int)uVar28) {
                uVar8 = uVar28;
              }
              local_128 = CONCAT44(uVar8,uVar7);
              lVar15 = FUN_140005d50(local_1f8,(longlong)&local_128,(undefined *)0x0);
              if (lVar15 == 0) {
                iVar9 = (int)puVar31;
                *(uint *)((longlong)local_1d0 + (longlong)iVar9 * 8 + 4) = uVar28;
                iVar22 = *(int *)((longlong)local_1e0 + (longlong)(int)uVar28 * 0xc) - *piVar14;
                iVar6 = *(int *)((longlong)local_1e0 + (longlong)(int)uVar28 * 0xc + 4) - piVar14[1]
                ;
                *(int *)((longlong)local_1d0 + (longlong)iVar9 * 8) =
                     iVar6 * iVar6 + iVar22 * iVar22;
                puVar31 = (undefined4 *)(ulonglong)(iVar9 + 1);
                lVar32 = local_1a0;
              }
            }
            uVar28 = (int)puVar11 + 1;
            puVar11 = (undefined4 *)(ulonglong)uVar28;
          } while ((uint)lVar32 != uVar28);
          _NumOfElements_00 = (undefined4 *)(longlong)(int)puVar31;
          piVar33 = (int *)0x8;
          piVar35 = (int *)&LAB_140004140;
          puVar24 = _NumOfElements_00;
          qsort(local_1d0,(size_t)_NumOfElements_00,8,(_PtFuncCompare *)&LAB_140004140);
          lVar32 = local_180;
          puVar11 = (undefined4 *)(ulonglong)local_1d8;
          if (0 < (int)puVar31) {
            local_160 = (ulonglong)uVar38 * 0xc;
            bVar5 = true;
            puVar24 = (undefined4 *)0x0;
            local_178 = puVar31;
            local_170 = _NumOfElements_00;
LAB_1400017f1:
            uVar28 = *(uint *)((longlong)local_1d0 + (longlong)puVar24 * 8 + 4);
            local_1e8 = (void *)(longlong)(int)uVar28;
            local_1f9 = bVar5;
            local_168 = puVar24;
            if (0 < (int)local_1f0) {
              puVar1 = (undefined8 *)((longlong)local_1e0 + (longlong)local_1e8 * 0xc);
              lVar15 = 0;
              do {
                if (((ulonglong)uVar28 * 0xc != lVar15) && (local_160 != lVar15)) {
                  local_120 = *(undefined4 *)(puVar1 + 1);
                  local_128 = *puVar1;
                  local_130 = piVar14[2];
                  local_138 = *(undefined8 *)piVar14;
                  local_140 = *(undefined4 *)((longlong)local_1e0 + lVar15 + 8);
                  local_148 = *(undefined8 *)((longlong)local_1e0 + lVar15);
                  local_150 = *(undefined4 *)((longlong)local_1e0 + lVar15 + 8);
                  local_158 = *(undefined8 *)((longlong)local_1e0 + lVar15);
                  piVar33 = (int *)&local_148;
                  piVar35 = (int *)&local_158;
                  uVar16 = FUN_140004170((int *)&local_128,(int *)&local_138,piVar33,piVar35);
                  if ((char)uVar16 != '\0') goto LAB_1400019ea;
                }
                lVar15 = lVar15 + 0xc;
              } while (lVar32 != lVar15);
            }
            uVar30 = 0;
            puVar19 = (uint *)FUN_1400059b0(local_1f8,0);
            if (puVar19 != (uint *)0x0) {
              puVar1 = (undefined8 *)((longlong)local_1e0 + (longlong)local_1e8 * 0xc);
              uVar29 = 1;
              do {
                uVar30 = uVar29;
                uVar7 = *puVar19;
                if ((uVar7 != uVar28) && (uVar7 != uVar38)) {
                  uVar8 = puVar19[1];
                  if ((uVar8 != (uint)local_1e8) && (uVar8 != uVar38)) {
                    local_120 = *(undefined4 *)(puVar1 + 1);
                    local_128 = *puVar1;
                    local_130 = piVar14[2];
                    local_138 = *(undefined8 *)piVar14;
                    local_140 = *(undefined4 *)
                                 ((longlong)local_1e0 + (longlong)(int)uVar7 * 0xc + 8);
                    local_148 = *(undefined8 *)((longlong)local_1e0 + (longlong)(int)uVar7 * 0xc);
                    local_150 = *(undefined4 *)
                                 ((longlong)local_1e0 + (longlong)(int)uVar8 * 0xc + 8);
                    local_158 = *(undefined8 *)((longlong)local_1e0 + (longlong)(int)uVar8 * 0xc);
                    piVar33 = (int *)&local_148;
                    piVar35 = (int *)&local_158;
                    uVar16 = FUN_140004170((int *)&local_128,(int *)&local_138,piVar33,piVar35);
                    if ((char)uVar16 != '\0') goto LAB_1400019ea;
                  }
                }
                iVar6 = (int)uVar30;
                puVar19 = (uint *)FUN_1400059b0(local_1f8,iVar6);
                uVar29 = (ulonglong)(iVar6 + 1);
                if (puVar19 == (uint *)0x0) break;
              } while( true );
            }
            puVar19 = FUN_140004a60(8,uVar30,piVar33,piVar35);
            if (uVar38 == uVar28) {
              piVar33 = (int *)0x1cb;
              _wassert(L"a != b",L"/puzzles/untangle.c",0x1cb);
            }
            uVar7 = uVar38;
            if ((int)uVar28 <= (int)uVar38) {
              uVar7 = (uint)local_1e8;
            }
            *puVar19 = uVar7;
            uVar7 = (uint)local_1e8;
            if ((int)uVar28 < (int)uVar38) {
              uVar7 = uVar38;
            }
            puVar19[1] = uVar7;
            puVar17 = (uint *)FUN_1400057c0(local_1f8,(longlong)puVar19,piVar33,piVar35);
            uVar30 = local_1f0;
            if (puVar17 != puVar19) {
              FUN_140004aa0(puVar19);
            }
            puVar11 = local_1a8;
            plVar12 = local_1c8;
            puVar24 = local_1a8 + lVar39 * 2;
            FUN_1400060d0(local_1c8,(longlong)puVar24);
            puVar11[lVar39 * 2] = puVar11[lVar39 * 2] + 1;
            FUN_1400057c0(plVar12,(longlong)puVar24,piVar33,piVar35);
            pvVar10 = local_1e8;
            puVar24 = puVar11 + (longlong)local_1e8 * 2;
            FUN_1400060d0(plVar12,(longlong)puVar24);
            puVar11[(longlong)pvVar10 * 2] = puVar11[(longlong)pvVar10 * 2] + 1;
            plVar13 = plVar12;
            FUN_1400057c0(plVar12,(longlong)puVar24,piVar33,piVar35);
            uVar29 = CONCAT71((int7)((ulonglong)plVar13 >> 8),1);
            puVar11 = (undefined4 *)(ulonglong)local_1d8;
            uVar23 = uVar29;
            plVar13 = local_1f8;
            if ((local_1f9 & 1) == 0) goto LAB_140001660;
            break;
          }
        }
        else {
          piVar33 = (int *)0x8;
          puVar24 = (undefined4 *)0x0;
          piVar35 = (int *)&LAB_140004140;
          qsort(local_1d0,0,8,(_PtFuncCompare *)&LAB_140004140);
        }
        uVar23 = local_1c0;
        uVar30 = local_1f0;
        plVar13 = local_1f8;
        uVar29 = local_1c0;
        if ((uint)puVar11 == local_1d4) break;
      }
    }
LAB_140001650:
    puVar11 = (undefined4 *)0x0;
    uVar29 = 0;
    if ((uVar23 & 1) == 0) {
      pvVar10 = FUN_140004a60(local_188,puVar24,piVar33,piVar35);
      uVar28 = (uint)uVar30;
      if ((int)uVar28 < 1) {
        pvVar18 = FUN_140004a60(local_1b8,puVar24,piVar33,piVar35);
      }
      else {
        if (7 < uVar28) {
          uVar29 = (ulonglong)(uVar28 & 0xfffffff8);
          puVar24 = (undefined4 *)((uVar29 - 8 >> 3) + 1);
          uVar23 = (ulonglong)((uint)puVar24 & 3);
          if (uVar29 - 8 < 0x18) {
            iVar6 = 0;
            iVar22 = 1;
            iVar9 = 2;
            iVar42 = 3;
            lVar32 = 0;
          }
          else {
            uVar25 = (ulonglong)puVar24 & 0xfffffffffffffffc;
            iVar6 = 0;
            iVar22 = 1;
            iVar9 = 2;
            iVar42 = 3;
            lVar32 = 0;
            do {
              piVar14 = (int *)((longlong)pvVar10 + lVar32 * 4);
              *piVar14 = iVar6;
              piVar14[1] = iVar22;
              piVar14[2] = iVar9;
              piVar14[3] = iVar42;
              piVar14 = (int *)((longlong)pvVar10 + lVar32 * 4 + 0x10);
              *piVar14 = iVar6 + 4;
              piVar14[1] = iVar22 + 4;
              piVar14[2] = iVar9 + 4;
              piVar14[3] = iVar42 + 4;
              piVar14 = (int *)((longlong)pvVar10 + lVar32 * 4 + 0x20);
              *piVar14 = iVar6 + 8;
              piVar14[1] = iVar22 + 8;
              piVar14[2] = iVar9 + 8;
              piVar14[3] = iVar42 + 8;
              piVar14 = (int *)((longlong)pvVar10 + lVar32 * 4 + 0x30);
              *piVar14 = iVar6 + 0xc;
              piVar14[1] = iVar22 + 0xc;
              piVar14[2] = iVar9 + 0xc;
              piVar14[3] = iVar42 + 0xc;
              piVar14 = (int *)((longlong)pvVar10 + lVar32 * 4 + 0x40);
              *piVar14 = iVar6 + 0x10;
              piVar14[1] = iVar22 + 0x10;
              piVar14[2] = iVar9 + 0x10;
              piVar14[3] = iVar42 + 0x10;
              piVar14 = (int *)((longlong)pvVar10 + lVar32 * 4 + 0x50);
              *piVar14 = iVar6 + 0x14;
              piVar14[1] = iVar22 + 0x14;
              piVar14[2] = iVar9 + 0x14;
              piVar14[3] = iVar42 + 0x14;
              piVar14 = (int *)((longlong)pvVar10 + lVar32 * 4 + 0x60);
              *piVar14 = iVar6 + 0x18;
              piVar14[1] = iVar22 + 0x18;
              piVar14[2] = iVar9 + 0x18;
              piVar14[3] = iVar42 + 0x18;
              piVar14 = (int *)((longlong)pvVar10 + lVar32 * 4 + 0x70);
              *piVar14 = iVar6 + 0x1c;
              piVar14[1] = iVar22 + 0x1c;
              piVar14[2] = iVar9 + 0x1c;
              piVar14[3] = iVar42 + 0x1c;
              lVar32 = lVar32 + 0x20;
              iVar6 = iVar6 + 0x20;
              iVar22 = iVar22 + 0x20;
              iVar9 = iVar9 + 0x20;
              iVar42 = iVar42 + 0x20;
              uVar25 = uVar25 - 4;
              puVar24 = (undefined4 *)0x0;
            } while (uVar25 != 0);
          }
          if (uVar23 == 0) goto joined_r0x000140001ccb;
          puVar24 = (undefined4 *)(lVar32 * 4 + 0x10 + (longlong)pvVar10);
          lVar32 = 0;
          do {
            piVar14 = (int *)((longlong)puVar24 + lVar32 + -0x10);
            *piVar14 = iVar6;
            piVar14[1] = iVar22;
            piVar14[2] = iVar9;
            piVar14[3] = iVar42;
            piVar14 = (int *)((longlong)puVar24 + lVar32);
            *piVar14 = iVar6 + 4;
            piVar14[1] = iVar22 + 4;
            piVar14[2] = iVar9 + 4;
            piVar14[3] = iVar42 + 4;
            iVar6 = iVar6 + 8;
            iVar22 = iVar22 + 8;
            iVar9 = iVar9 + 8;
            iVar42 = iVar42 + 8;
            lVar32 = lVar32 + 0x20;
            if (uVar23 << 5 == lVar32) goto joined_r0x000140001ccb;
          } while( true );
        }
        uVar29 = 0;
        do {
          *(int *)((longlong)pvVar10 + uVar29 * 4) = (int)uVar29;
          uVar29 = uVar29 + 1;
joined_r0x000140001ccb:
        } while (uVar29 != uVar30);
        pvVar18 = FUN_140004a60(local_1b8,puVar24,piVar33,piVar35);
        if (0 < (int)uVar28) {
          iVar6 = (local_194 * 0xc0) / 7;
          iVar22 = local_194 << 5;
          puVar24 = (undefined4 *)((longlong)pvVar18 + 8);
          lVar32 = 0;
          do {
            dVar43 = ((double)(int)lVar32 * 3.141592653589793) / (double)(int)uVar28;
            dVar40 = sin(dVar43);
            dVar43 = cos(dVar43);
            puVar24[-2] = (int)(dVar40 * (double)iVar6 + (double)iVar22 + 0.5);
            puVar24[-1] = (int)(dVar43 * (double)-iVar6 + (double)iVar22 + 0.5);
            *puVar24 = 0x40;
            lVar32 = lVar32 + 2;
            puVar24 = puVar24 + 3;
            plVar13 = local_1f8;
          } while (uVar30 * 2 != lVar32);
        }
      }
      do {
        do {
          FUN_140005430((longlong)pvVar10,(uint)local_1f0,4,(char *)local_190);
          piVar33 = (int *)FUN_1400059b0(plVar13,0);
        } while (piVar33 == (int *)0x0);
        iVar22 = 0;
        iVar6 = 2;
        do {
          iVar22 = iVar22 + 1;
          piVar35 = (int *)FUN_1400059b0(plVar13,iVar22);
          iVar9 = iVar6;
          plVar12 = local_1f8;
          while (local_1f8 = plVar12, piVar35 != (int *)0x0) {
            iVar42 = *piVar35;
            iVar41 = *piVar33;
            if (iVar42 != iVar41) {
              iVar3 = piVar33[1];
              if (((iVar42 != iVar3) && (iVar4 = piVar35[1], iVar4 != iVar41)) && (iVar4 != iVar3))
              {
                lVar27 = (longlong)*(int *)((longlong)pvVar10 + (longlong)iVar3 * 4);
                lVar15 = (longlong)*(int *)((longlong)pvVar10 + (longlong)iVar41 * 4);
                lVar32 = (longlong)*(int *)((longlong)pvVar10 + (longlong)iVar4 * 4);
                lVar39 = (longlong)*(int *)((longlong)pvVar10 + (longlong)iVar42 * 4);
                local_120 = *(undefined4 *)((longlong)pvVar18 + lVar39 * 0xc + 8);
                local_128 = *(undefined8 *)((longlong)pvVar18 + lVar39 * 0xc);
                local_130 = *(int *)((longlong)pvVar18 + lVar32 * 0xc + 8);
                local_138 = *(undefined8 *)((longlong)pvVar18 + lVar32 * 0xc);
                local_140 = *(undefined4 *)((longlong)pvVar18 + lVar15 * 0xc + 8);
                local_148 = *(undefined8 *)((longlong)pvVar18 + lVar15 * 0xc);
                local_150 = *(undefined4 *)((longlong)pvVar18 + lVar27 * 0xc + 8);
                local_158 = *(undefined8 *)((longlong)pvVar18 + lVar27 * 0xc);
                piVar35 = (int *)&local_138;
                piVar14 = (int *)&local_148;
                piVar36 = (int *)&local_158;
                uVar16 = FUN_140004170((int *)&local_128,piVar35,piVar14,piVar36);
                plVar13 = plVar12;
                if ((char)uVar16 != '\0') {
                  uVar28 = FUN_140005780(plVar12);
                  _NumOfElements = (wchar_t *)(longlong)(int)uVar28;
                  puVar19 = FUN_140004a60((longlong)_NumOfElements * 8,piVar35,piVar14,piVar36);
                  iVar6 = 0;
                  piVar33 = (int *)FUN_1400059b0(plVar12,0);
                  lVar32 = 0;
                  if (piVar33 != (int *)0x0) {
                    local_1e8 = (void *)CONCAT44(local_1e8._4_4_,uVar28);
                    lVar32 = 0;
                    iVar6 = 0;
                    do {
                      if ((longlong)_NumOfElements <= lVar32) {
                        _wassert(L"i < m",L"/puzzles/untangle.c",0x246);
                      }
                      uVar28 = *(uint *)((longlong)pvVar10 + (longlong)piVar33[1] * 4);
                      uVar38 = *(uint *)((longlong)pvVar10 + (longlong)*piVar33 * 4);
                      uVar7 = uVar28;
                      if ((int)uVar38 < (int)uVar28) {
                        uVar7 = uVar38;
                      }
                      puVar19[lVar32 * 2] = uVar7;
                      if ((int)uVar28 < (int)uVar38) {
                        uVar28 = uVar38;
                      }
                      puVar19[lVar32 * 2 + 1] = uVar28;
                      iVar22 = FUN_140001000(&local_128,&DAT_1400182a5,(ulonglong)uVar7,
                                             (ulonglong)uVar28);
                      iVar6 = iVar22 + ((iVar6 + 1) - (uint)(lVar32 == 0));
                      lVar32 = lVar32 + 1;
                      piVar33 = (int *)FUN_1400059b0(local_1f8,(int)lVar32);
                    } while (piVar33 != (int *)0x0);
                    uVar28 = (uint)local_1e8;
                  }
                  if ((uint)lVar32 != uVar28) {
                    _wassert(L"i == m",L"/puzzles/untangle.c",0x254);
                  }
                  puVar37 = &LAB_140004140;
                  puVar34 = (undefined *)0x8;
                  qsort(puVar19,(size_t)_NumOfElements,8,(_PtFuncCompare *)&LAB_140004140);
                  pvVar20 = FUN_140004a60((longlong)(iVar6 + 1),_NumOfElements,puVar34,puVar37);
                  if ((int)uVar28 < 1) {
                    iVar22 = 0;
                  }
                  else {
                    puVar37 = (undefined1 *)(ulonglong)*puVar19;
                    local_218 = puVar19[1];
                    _NumOfElements =
                         L"猥搥┭d瑓瑡捩尀䌀䵏佂佂X䕒呓剁T猥䑟䙅啁呌䔀䥄T猥偟䕒䕓協匀䅔䕔佐S偃剁䵁S华䅔䕔S啁䥘䙎O啂呔乏嘀剅䥓乏伀K䥕─彳䥔䕌䥓䕚䴀噏E体噌E䥔䕍䜀䵁E䅓䕖䥆䕌䜀浡⁥䑉䠀塅䕓䑅倀䥒䑖卅C呓呁䍉䠀浴䡬汥䅰䄀偐䅄䅔䄀敲礠畯猠牵⁥潹⁵慷瑮琠\x206f癯牥牷瑩⁥桴⁥楦敬∠⸥猪㼢㴀─㩳搥:獭瑣獬獟慴畴扳牡㈳㄀㄀〰〮唀敳猠慴畴彳慢⡲\x2029潴映汩\x206c桴獩椠⹮☀牐湩⹴⸮☀畃瑳浯⸮.匦癡⹥⸮刀湡潤洦匠敥⹤⸮☀潌摡⸮.灓捥♩楦⹣⸮愀换敤杦楨歪浬潮煰獲畴睶祸⵺Ⰰ匀灵汰敩⁤牡畧敭瑮∠猥•獩渠楥桴牥愠朠浡⁥䑉⠠猥\x2029潮⁲⁡慳敶映汩⁥┨⥳倀楲瑮摥瀠穵決獥映潲\x206d猥⠠牦浯匠浩湯吠瑡慨❭⁳潐瑲扡敬倠穵決⁥潃汬捥楴湯)畐空敬⁳渨\x206f慧敭猠汥捥整⥤䨀⡉❠怬猥⤧嘀污敵映牯戠潯敬湡眠獡渠瑯✠牴敵‧牯✠慦獬❥⌀嬀搥┺㈰嵤 ›渀\x206f楷摮睯›砰砥\n湕扡敬琠\x206f潬摡瀠敲敦敲据獥映汩⁥猥਺猥\n牄睡湩\x2067偁⁉敶獲潩\x206e業浳瑡档›硥数瑣摥›搥\x202c捡畴污›搥\n汁\x206c楆敬⁳⨨⨮)*"
                    ;
                    puVar34 = &DAT_1400185c5;
                    iVar22 = FUN_140001000(pvVar20,&DAT_1400182a3,&DAT_1400185c5,puVar37);
                    if (uVar28 != 1) {
                      lVar32 = 0;
                      do {
                        puVar37 = (undefined1 *)(ulonglong)puVar19[lVar32 * 2 + 2];
                        local_218 = puVar19[lVar32 * 2 + 3];
                        _NumOfElements =
                             L"猥搥┭d瑓瑡捩尀䌀䵏佂佂X䕒呓剁T猥䑟䙅啁呌䔀䥄T猥偟䕒䕓協匀䅔䕔佐S偃剁䵁S华䅔䕔S啁䥘䙎O啂呔乏嘀剅䥓乏伀K䥕─彳䥔䕌䥓䕚䴀噏E体噌E䥔䕍䜀䵁E䅓䕖䥆䕌䜀浡⁥䑉䠀塅䕓䑅倀䥒䑖卅C呓呁䍉䠀浴䡬汥䅰䄀偐䅄䅔䄀敲礠畯猠牵⁥潹⁵慷瑮琠\x206f癯牥牷瑩⁥桴⁥楦敬∠⸥猪㼢㴀─㩳搥:獭瑣獬獟慴畴扳牡㈳㄀㄀〰〮唀敳猠慴畴彳慢⡲\x2029潴映汩\x206c桴獩椠⹮☀牐湩⹴⸮☀畃瑳浯⸮.匦癡⹥⸮刀湡潤洦匠敥⹤⸮☀潌摡⸮.灓捥♩楦⹣⸮愀换敤杦楨歪浬潮煰獲畴睶祸⵺Ⰰ匀灵汰敩⁤牡畧敭瑮∠猥•獩渠楥桴牥愠朠浡⁥䑉⠠猥\x2029潮⁲⁡慳敶映汩⁥┨⥳倀楲瑮摥瀠穵決獥映潲\x206d猥⠠牦浯匠浩湯吠瑡慨❭⁳潐瑲扡敬倠穵決⁥潃汬捥楴湯)畐空敬⁳渨\x206f慧敭猠汥捥整⥤䨀⡉❠怬猥⤧嘀污敵映牯戠潯敬湡眠獡渠瑯✠牴敵‧牯✠慦獬❥⌀嬀搥┺㈰嵤 ›渀\x206f楷摮睯›砰砥\n湕扡敬琠\x206f潬摡瀠敲敦敲据獥映汩⁥猥਺猥\n牄睡湩\x2067偁⁉敶獲潩\x206e業浳瑡档›硥数瑣摥›搥\x202c捡畴污›搥\n汁\x206c楆敬⁳⨨⨮)*"
                        ;
                        puVar34 = &DAT_14001844c;
                        iVar9 = FUN_140001000((longlong)pvVar20 + (longlong)iVar22,&DAT_1400182a3,
                                              &DAT_14001844c,puVar37);
                        iVar22 = iVar22 + iVar9;
                        lVar32 = lVar32 + 1;
                      } while ((ulonglong)uVar28 - 1 != lVar32);
                    }
                  }
                  if (iVar22 != iVar6) {
                    _NumOfElements = L"/puzzles/untangle.c";
                    puVar34 = (undefined *)0x262;
                    _wassert(L"k == retlen",L"/puzzles/untangle.c",0x262);
                  }
                  local_1e8 = pvVar20;
                  FUN_140004aa0(puVar19);
                  plVar12 = local_1f8;
                  if ((int)local_1f0 < 1) {
                    puVar37 = FUN_140004a60(2,_NumOfElements,puVar34,puVar37);
                    *puVar37 = 0x53;
                  }
                  else {
                    iVar6 = 2;
                    uVar30 = 0;
                    puVar21 = local_1e0;
                    do {
                      lVar32 = (longlong)*(int *)((longlong)pvVar10 + uVar30 * 4);
                      local_210 = (uint)puVar21[1];
                      *(uint *)((longlong)pvVar18 + lVar32 * 0xc + 8) = local_210;
                      uVar29 = *puVar21;
                      *(ulonglong *)((longlong)pvVar18 + lVar32 * 0xc) = uVar29;
                      if ((local_210 & 1) == 0) {
                        iVar22 = *(int *)((longlong)pvVar18 + lVar32 * 0xc + 4);
                      }
                      else {
                        uVar29 = (ulonglong)(uint)((int)uVar29 * 2);
                        iVar22 = *(int *)((longlong)pvVar18 + lVar32 * 0xc + 4) * 2;
                        local_210 = local_210 * 2;
                        *(uint *)((longlong)pvVar18 + lVar32 * 0xc + 8) = local_210;
                      }
                      uVar28 = (int)uVar29 + (int)local_210 / 2;
                      uVar23 = (ulonglong)uVar28;
                      *(uint *)((longlong)pvVar18 + lVar32 * 0xc) = uVar28;
                      local_218 = (int)local_210 / 2 + iVar22;
                      *(uint *)((longlong)pvVar18 + lVar32 * 0xc + 4) = local_218;
                      pcVar26 = ";P%d:%ld,%ld/%ld";
                      uVar29 = uVar30 & 0xffffffff;
                      iVar22 = FUN_140001000(&local_128,";P%d:%ld,%ld/%ld",uVar29,uVar23);
                      iVar6 = iVar6 + iVar22;
                      uVar30 = uVar30 + 1;
                      puVar21 = (ulonglong *)((longlong)puVar21 + 0xc);
                    } while (local_1f0 != uVar30);
                    puVar37 = FUN_140004a60((longlong)iVar6,pcVar26,uVar29,uVar23);
                    uVar30 = local_1f0;
                    *puVar37 = 0x53;
                    if ((int)local_1f0 < 1) {
                      plVar12 = local_1f8;
                      if (1 < iVar6) goto LAB_14000225d;
                    }
                    else {
                      puVar19 = (uint *)((longlong)pvVar18 + 8);
                      iVar22 = 1;
                      uVar29 = 0;
                      do {
                        local_210 = *puVar19;
                        local_218 = puVar19[-1];
                        iVar9 = FUN_140001000(puVar37 + iVar22,";P%d:%ld,%ld/%ld",
                                              uVar29 & 0xffffffff,(ulonglong)puVar19[-2]);
                        iVar22 = iVar22 + iVar9;
                        uVar29 = uVar29 + 1;
                        puVar19 = puVar19 + 3;
                      } while (uVar30 != uVar29);
                      plVar12 = local_1f8;
                      if (iVar22 < iVar6) goto LAB_14000225d;
                    }
                    _wassert(L"k < auxlen",L"/puzzles/untangle.c",0x32b);
                    plVar12 = local_1f8;
                  }
LAB_14000225d:
                  *local_1b0 = puVar37;
                  FUN_140004aa0(pvVar18);
                  FUN_140004aa0(pvVar10);
                  FUN_140004aa0(local_1d0);
                  FUN_140005710(local_1c8);
                  puVar24 = local_1a8;
                  do {
                    FUN_140004aa0(puVar24);
                    puVar24 = (undefined4 *)FUN_140005d70(plVar12,0);
                  } while (puVar24 != (undefined4 *)0x0);
                  FUN_140005710(plVar12);
                  FUN_140004aa0(local_1e0);
                  FUN_140016090(local_d0 ^ (ulonglong)auStack_238);
                  return local_1e8;
                }
              }
            }
            piVar35 = (int *)FUN_1400059b0(plVar13,iVar9);
            iVar9 = iVar9 + 1;
            plVar12 = local_1f8;
          }
          piVar33 = (int *)FUN_1400059b0(plVar13,iVar22);
          iVar6 = iVar6 + 1;
        } while (piVar33 != (int *)0x0);
      } while( true );
    }
  } while( true );
LAB_1400019ea:
  puVar24 = (undefined4 *)((longlong)local_168 + 1);
  bVar5 = (longlong)puVar24 < (longlong)local_170;
  if (puVar24 == local_178) goto code_r0x000140001a17;
  goto LAB_1400017f1;
code_r0x000140001a17:
  uVar23 = local_1c0;
  uVar30 = local_1f0;
  plVar13 = local_1f8;
  plVar12 = local_1c8;
  if (((longlong)puVar24 < (longlong)local_170) ||
     (puVar11 = (undefined4 *)(ulonglong)local_1d8, uVar29 = local_1c0, local_1d8 == local_1d4))
  goto LAB_140001650;
  goto LAB_14000166b;
}


//==== 0x140002340 {"status":"resolved","address":"0x140002340","name":"FUN_140002340"}

char * FUN_140002340(int *param_1,byte *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  byte *_Str;
  char *pcVar4;
  byte bVar5;
  
  pcVar4 = "Number out of range in game description";
  do {
    bVar5 = *param_2;
    if (bVar5 == 0) {
      return (char *)0x0;
    }
    iVar2 = atoi((char *)param_2);
    if (iVar2 < 0) {
      return pcVar4;
    }
    iVar1 = *param_1;
    if (iVar1 <= iVar2) {
      return pcVar4;
    }
    _Str = param_2 + 1;
    do {
      if (9 < bVar5 - 0x30) break;
      bVar5 = *_Str;
      _Str = _Str + 1;
    } while (bVar5 != 0);
    if (bVar5 != 0x2d) {
      return "Expected \'-\' after number in game description";
    }
    iVar3 = atoi((char *)_Str);
    if (iVar3 < 0) {
      return pcVar4;
    }
    if (iVar1 <= iVar3) {
      return pcVar4;
    }
    do {
      param_2 = _Str;
      bVar5 = *param_2;
      if (bVar5 == 0) break;
      _Str = param_2 + 1;
    } while (bVar5 - 0x30 < 10);
    if ((bVar5 != 0) && (param_2 = param_2 + 1, bVar5 != 0x2c)) {
      return "Expected \',\' after number in game description";
    }
    if (iVar2 == iVar3) {
      return "Node linked to itself in game description";
    }
  } while( true );
}


//==== 0x140002450 {"status":"resolved","address":"0x140002450","name":"FUN_140002450"}

uint * FUN_140002450(undefined8 param_1,uint *param_2,byte *param_3,undefined8 param_4)

{
  byte bVar1;
  longlong *plVar2;
  double dVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  void *pvVar9;
  undefined8 uVar10;
  wchar_t *pwVar11;
  wchar_t *pwVar12;
  wchar_t *pwVar13;
  undefined4 *puVar14;
  longlong lVar15;
  byte *pbVar16;
  byte *pbVar17;
  byte *pbVar18;
  double dVar19;
  double dVar20;
  
  uVar5 = *param_2;
  pwVar13 = (wchar_t *)param_2;
  pbVar18 = param_3;
  puVar8 = FUN_140004a60(0x30,param_2,param_3,param_4);
  *puVar8 = *param_2;
  uVar4 = FUN_140003f30(uVar5 * 3);
  puVar8[2] = uVar4;
  puVar8[1] = uVar4;
  pvVar9 = FUN_140004a60((longlong)(int)uVar5 * 0xc,pwVar13,pbVar18,param_4);
  *(void **)(puVar8 + 4) = pvVar9;
  if (0 < (longlong)(int)uVar5) {
    iVar7 = puVar8[1] * 0xc0;
    pwVar13 = (wchar_t *)(ulonglong)(uint)-(iVar7 >> 0x1f);
    iVar7 = iVar7 / 7;
    dVar3 = (double)(int)(puVar8[1] << 5);
    puVar14 = (undefined4 *)((longlong)pvVar9 + 8);
    lVar15 = 0;
    do {
      dVar20 = ((double)(int)lVar15 * 3.141592653589793) / (double)(int)uVar5;
      dVar19 = sin(dVar20);
      dVar20 = cos(dVar20);
      puVar14[-2] = (int)(dVar19 * (double)iVar7 + dVar3 + 0.5);
      puVar14[-1] = (int)(dVar20 * (double)-iVar7 + dVar3 + 0.5);
      *puVar14 = 0x40;
      lVar15 = lVar15 + 2;
      puVar14 = puVar14 + 3;
    } while ((ulonglong)uVar5 * 2 != lVar15);
  }
  puVar14 = FUN_140004a60(0x10,pwVar13,pbVar18,param_4);
  *(undefined4 **)(puVar8 + 6) = puVar14;
  *puVar14 = 1;
  uVar10 = FUN_1400056e0(&LAB_140004140,pwVar13,pbVar18,param_4);
  *(undefined8 *)(*(longlong *)(puVar8 + 6) + 8) = uVar10;
  *(undefined1 *)((longlong)puVar8 + 0x2a) = 0;
  *(undefined2 *)(puVar8 + 10) = 0;
  bVar1 = *param_3;
  do {
    if (bVar1 == 0) {
      iVar7 = FUN_140005780(*(longlong **)(*(longlong *)(puVar8 + 6) + 8));
      pvVar9 = FUN_140004a60((longlong)iVar7 << 2,pwVar13,pbVar18,param_4);
      *(void **)(puVar8 + 8) = pvVar9;
      FUN_1400044f0((longlong)puVar8);
      return puVar8;
    }
    uVar5 = atoi((char *)param_3);
    if (((int)uVar5 < 0) || ((int)*param_2 <= (int)uVar5)) {
      pwVar13 = L"/puzzles/untangle.c";
      pbVar18 = (byte *)0x393;
      _wassert(L"a >= 0 && a < params->n",L"/puzzles/untangle.c",0x393);
    }
    do {
      bVar1 = *param_3;
      param_3 = param_3 + 1;
      if (bVar1 == 0) break;
    } while (bVar1 - 0x30 < 10);
    if (bVar1 != 0x2d) {
      pwVar13 = L"/puzzles/untangle.c";
      pbVar18 = (byte *)0x395;
      _wassert(L"*desc == \'-\'",L"/puzzles/untangle.c",0x395);
    }
    uVar4 = atoi((char *)param_3);
    if (((int)uVar4 < 0) || ((int)*param_2 <= (int)uVar4)) {
      pwVar13 = L"/puzzles/untangle.c";
      pbVar18 = (byte *)0x398;
      _wassert(L"b >= 0 && b < params->n",L"/puzzles/untangle.c",0x398);
    }
    do {
      pbVar16 = param_3;
      bVar1 = *pbVar16;
      pbVar17 = pbVar16 + 1;
      param_3 = pbVar17;
      if (bVar1 == 0) break;
    } while (bVar1 - 0x30 < 10);
    if ((bVar1 != 0x2c) && (param_3 = pbVar16, bVar1 != 0)) {
      pwVar13 = L"/puzzles/untangle.c";
      pbVar18 = (byte *)0x39b;
      _wassert(L"*desc == \',\'",L"/puzzles/untangle.c",0x39b);
      param_3 = pbVar17;
    }
    plVar2 = *(longlong **)(*(longlong *)(puVar8 + 6) + 8);
    pwVar11 = FUN_140004a60(8,pwVar13,pbVar18,param_4);
    if (uVar5 == uVar4) {
      pbVar18 = (byte *)0x1cb;
      _wassert(L"a != b",L"/puzzles/untangle.c",0x1cb);
    }
    uVar6 = uVar4;
    if ((int)uVar5 < (int)uVar4) {
      uVar6 = uVar5;
    }
    *(uint *)pwVar11 = uVar6;
    if ((int)uVar4 < (int)uVar5) {
      uVar4 = uVar5;
    }
    *(uint *)(pwVar11 + 2) = uVar4;
    pwVar13 = pwVar11;
    pwVar12 = (wchar_t *)FUN_1400057c0(plVar2,(longlong)pwVar11,pbVar18,param_4);
    if (pwVar12 != pwVar11) {
      FUN_140004aa0(pwVar11);
    }
    bVar1 = *param_3;
  } while( true );
}


//==== 0x1400027e0 {"status":"resolved","address":"0x1400027e0","name":"FUN_1400027e0"}

int * FUN_1400027e0(int *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  void *pvVar4;
  void *pvVar5;
  size_t _Size;
  
  iVar2 = *param_1;
  piVar3 = FUN_140004a60(0x30,param_2,param_3,param_4);
  *piVar3 = *param_1;
  piVar3[1] = param_1[1];
  piVar3[2] = param_1[2];
  _Size = (longlong)iVar2 * 0xc;
  pvVar4 = FUN_140004a60(_Size,param_2,param_3,param_4);
  *(void **)(piVar3 + 4) = pvVar4;
  pvVar5 = *(void **)(param_1 + 4);
  memcpy(pvVar4,pvVar5,_Size);
  piVar1 = *(int **)(param_1 + 6);
  *(int **)(piVar3 + 6) = piVar1;
  *piVar1 = *piVar1 + 1;
  *(char *)(piVar3 + 10) = (char)param_1[10];
  *(undefined1 *)((longlong)piVar3 + 0x29) = *(undefined1 *)((longlong)param_1 + 0x29);
  *(undefined1 *)((longlong)piVar3 + 0x2a) = *(undefined1 *)((longlong)param_1 + 0x2a);
  iVar2 = FUN_140005780(*(longlong **)(*(longlong *)(piVar3 + 6) + 8));
  pvVar4 = FUN_140004a60((longlong)iVar2 << 2,pvVar5,_Size,param_4);
  *(void **)(piVar3 + 8) = pvVar4;
  pvVar5 = *(void **)(param_1 + 8);
  iVar2 = FUN_140005780(*(longlong **)(*(longlong *)(piVar3 + 6) + 8));
  memcpy(pvVar4,pvVar5,(longlong)iVar2 << 2);
  return piVar3;
}


//==== 0x1400028a0 {"status":"resolved","address":"0x1400028a0","name":"FUN_1400028a0"}

void FUN_1400028a0(void *param_1)

{
  int iVar1;
  void *pvVar2;
  
  iVar1 = **(int **)((longlong)param_1 + 0x18);
  **(int **)((longlong)param_1 + 0x18) = iVar1 + -1;
  if (iVar1 < 2) {
    while (pvVar2 = (void *)FUN_140005d70(*(longlong **)
                                           (*(longlong *)((longlong)param_1 + 0x18) + 8),0),
          pvVar2 != (void *)0x0) {
      FUN_140004aa0(pvVar2);
    }
    FUN_140005710(*(undefined8 **)(*(longlong *)((longlong)param_1 + 0x18) + 8));
    FUN_140004aa0(*(void **)((longlong)param_1 + 0x18));
  }
  FUN_140004aa0(*(void **)((longlong)param_1 + 0x20));
  FUN_140004aa0(*(void **)((longlong)param_1 + 0x10));
  FUN_140004aa0(param_1);
  return;
}


//==== 0x140002920 {"status":"resolved","address":"0x140002920","name":"FUN_140002920"}

undefined2 * FUN_140002920(uint *param_1,longlong param_2,uint *param_3,uint *param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  undefined2 *puVar6;
  longlong lVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  uint uVar11;
  ulonglong uVar13;
  uint *puVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  undefined1 auStack_1b8 [32];
  uint *local_198;
  uint *local_190;
  uint *local_188;
  ulonglong local_180;
  uint *local_178;
  longlong local_170;
  uint local_164;
  uint local_160;
  uint local_15c;
  uint local_158 [20];
  uint local_108 [6];
  ulonglong local_f0;
  ulonglong uVar12;
  
  local_f0 = DAT_14001c000 ^ (ulonglong)auStack_1b8;
  if (param_3 == (uint *)0x0) {
    *(char **)param_4 = "Solution not known for this puzzle";
LAB_140002e1c:
    puVar6 = (undefined2 *)0x0;
  }
  else {
    uVar11 = *param_1;
    local_180 = (ulonglong)(int)uVar11;
    puVar10 = param_3;
    local_178 = param_4;
    puVar5 = FUN_140004a60(local_180 * 0xc,param_2,param_3,param_4);
    if (0 < (int)uVar11) {
      lVar7 = (longlong)param_3 + 1;
      puVar14 = puVar5 + 2;
      uVar13 = 0;
      do {
        local_188 = local_108;
        local_190 = &local_164;
        local_198 = &local_160;
        puVar10 = local_158;
        param_4 = &local_15c;
        iVar3 = FUN_1400046d0(lVar7,";P%d:%ld,%ld/%ld%n",local_158,&local_15c);
        if ((iVar3 != 4) || (uVar13 != local_158[0])) {
          *(char **)local_178 = "Internal error: aux_info badly formatted";
          FUN_140004aa0(puVar5);
          goto LAB_140002e1c;
        }
        puVar14[-2] = local_15c;
        puVar14[-1] = local_160;
        *puVar14 = local_164;
        lVar7 = lVar7 + (int)local_108[0];
        uVar13 = uVar13 + 1;
        puVar14 = puVar14 + 3;
      } while (uVar11 != uVar13);
    }
    uVar13 = local_180;
    fVar21 = 0.0;
    uVar9 = 0xffffffff;
    uVar8 = 0;
    do {
      local_108[0] = 0;
      local_108[1] = 0;
      local_108[2] = 0;
      local_108[3] = 0;
      local_108[uVar8 & 1] = -(uint)((uVar8 & 2) == 0) | 1;
      local_108[uVar8 & 1 ^ 3] = -(uint)((uVar8 & 4) == 0) | 1;
      fVar16 = 0.0;
      if (0 < (int)uVar11) {
        fVar22 = (float)*(int *)(param_2 + 4) * 0.5;
        fVar17 = (float)*(int *)(param_2 + 8) * 0.5;
        fVar16 = 0.0;
        lVar7 = 0;
        do {
          uVar1 = *(undefined8 *)((longlong)puVar5 + lVar7 + 4);
          fVar19 = (float)(int)((ulonglong)uVar1 >> 0x20);
          uVar2 = *(undefined8 *)(*(longlong *)(param_2 + 0x10) + 4 + lVar7);
          fVar20 = (float)(int)((ulonglong)uVar2 >> 0x20);
          fVar15 = (float)*(int *)((longlong)puVar5 + lVar7) / fVar19 - fVar22;
          fVar18 = (float)(int)uVar1 / fVar19 - fVar17;
          fVar19 = ((float)(int)local_108[0] * fVar15 + fVar18 * (float)(int)local_108[1] + fVar22)
                   - (float)*(int *)(*(longlong *)(param_2 + 0x10) + lVar7) / fVar20;
          fVar15 = (fVar15 * (float)(int)local_108[2] + fVar18 * (float)(int)local_108[3] + fVar17)
                   - (float)(int)uVar2 / fVar20;
          fVar16 = fVar16 + fVar19 * fVar19 + fVar15 * fVar15;
          lVar7 = lVar7 + 0xc;
        } while ((ulonglong)uVar11 * 0xc != lVar7);
      }
      if (fVar16 < fVar21 || (int)uVar9 < 0) {
        uVar9 = uVar8;
        fVar21 = fVar16;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 != 8);
    if ((int)uVar9 < 0) {
      puVar10 = (uint *)0x436;
      _wassert(L"besti >= 0",L"/puzzles/untangle.c",0x436);
    }
    local_108[0] = 0;
    local_108[1] = 0;
    local_108[2] = 0;
    local_108[3] = 0;
    local_108[uVar9 & 1] = -(uint)((uVar9 & 2) == 0) | 1;
    uVar8 = -(uint)((uVar9 & 4) == 0) | 1;
    local_108[uVar9 & 1 ^ 3] = uVar8;
    puVar6 = FUN_140004a60(0x100,(ulonglong)uVar8,puVar10,param_4);
    *puVar6 = 0x53;
    if (0 < (int)uVar11) {
      fVar17 = (float)(int)local_108[0];
      fVar16 = (float)(int)local_108[1];
      fVar22 = (float)(int)local_108[2];
      fVar21 = (float)(int)local_108[3];
      local_178 = (uint *)(uVar13 & 0xffffffff);
      local_180 = CONCAT44(local_180._4_4_,0x100);
      puVar14 = (uint *)0x0;
      puVar10 = puVar5;
      iVar3 = 1;
      local_170 = param_2;
      do {
        fVar18 = (float)(int)((ulonglong)*(undefined8 *)(puVar10 + 1) >> 0x20);
        fVar20 = (float)*(int *)(local_170 + 4) * 0.5;
        fVar19 = (float)*(int *)(local_170 + 8) * 0.5;
        fVar15 = (float)(int)*puVar10 / fVar18 - fVar20;
        fVar18 = (float)(int)*(undefined8 *)(puVar10 + 1) / fVar18 - fVar19;
        fVar20 = fVar17 * fVar15 + fVar18 * fVar16 + fVar20;
        fVar19 = fVar15 * fVar22 + fVar18 * fVar21 + fVar19;
        puVar10[2] = 2;
        uVar11 = (uint)(fVar20 + fVar20 + 0.5);
        uVar12 = (ulonglong)uVar11;
        *puVar10 = uVar11;
        uVar11 = (uint)(fVar19 + fVar19 + 0.5);
        puVar10[1] = uVar11;
        local_198 = (uint *)CONCAT44(local_198._4_4_,uVar11);
        local_190 = (uint *)CONCAT44(local_190._4_4_,2);
        uVar13 = (ulonglong)puVar14 & 0xffffffff;
        iVar4 = FUN_140001000(local_158,";P%d:%ld,%ld/%ld",uVar13,uVar12);
        iVar4 = iVar4 + iVar3;
        if ((int)local_180 <= iVar4) {
          local_180 = CONCAT44(local_180._4_4_,iVar4 + 0x100);
          puVar6 = FUN_140004ab0(puVar6,(longlong)(iVar4 + 0x100),uVar13,uVar12);
        }
        strcpy((char *)((longlong)iVar3 + (longlong)puVar6),(char *)local_158);
        puVar14 = (uint *)((longlong)puVar14 + 1);
        puVar10 = puVar10 + 3;
        iVar3 = iVar4;
      } while (local_178 != puVar14);
    }
    FUN_140004aa0(puVar5);
  }
  FUN_140016090(local_f0 ^ (ulonglong)auStack_1b8);
  return puVar6;
}


//==== 0x140002ea0 {"status":"resolved","address":"0x140002ea0","name":"FUN_140002ea0"}

void FUN_140002ea0(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  
  puVar1 = FUN_140004a60(0xc0,param_2,param_3,param_4);
  *puVar1 = "Snap points to a grid";
  puVar1[1] = "snap-to-grid";
  *(undefined4 *)(puVar1 + 2) = 2;
  *(undefined1 *)(puVar1 + 3) = *(undefined1 *)(param_1 + 0x20);
  puVar1[6] = "Show edges that cross another edge";
  puVar1[7] = "show-crossed-edges";
  *(undefined4 *)(puVar1 + 8) = 2;
  *(undefined1 *)(puVar1 + 9) = *(undefined1 *)(param_1 + 0x21);
  puVar1[0xc] = "Display style for vertices";
  puVar1[0xd] = "vertex-style";
  *(undefined4 *)(puVar1 + 0xe) = 1;
  puVar1[0xf] = ":Circles:Numbers";
  puVar1[0x10] = ":circle:number";
  *(uint *)(puVar1 + 0x11) = (uint)*(byte *)(param_1 + 0x22);
  puVar1[0x12] = 0;
  *(undefined4 *)(puVar1 + 0x14) = 3;
  return;
}


//==== 0x140002f60 {"status":"unknown","error":{"code":"invalid_request","category":"invalid_input","message":"Analysis input is invalid. Check the arguments and try again.","retryable":true,"remediation":{"action":"Correct the listed arguments and retry."},"details":{"operation":"procedure_address","issues":[{"path":[],"reason":"invalid_value","message":"No procedure exists at the requested address: 0x140002f60"}]}}}
{"code":"invalid_request","category":"invalid_input","message":"Analysis input is invalid. Check the arguments and try again.","retryable":true,"remediation":{"action":"Correct the listed arguments and retry."},"details":{"operation":"procedure_pseudo_code","issues":[{"path":[],"reason":"invalid_value","message":"No procedure exists at the requested address: 0x140002f60"}]}}
//==== 0x140002f80 {"status":"resolved","address":"0x140002f80","name":"FUN_140002f80"}

void FUN_140002f80(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  
  puVar1 = FUN_140004a60(0x24,param_2,param_3,param_4);
  *puVar1 = 0xffffffffffffffff;
  *(undefined2 *)((longlong)puVar1 + 0x14) = 0;
  *(undefined2 *)(puVar1 + 4) = 0;
  *(undefined1 *)((longlong)puVar1 + 0x22) = 0;
  return;
}


//==== 0x140002fb0 {"status":"unknown","error":{"code":"invalid_request","category":"invalid_input","message":"Analysis input is invalid. Check the arguments and try again.","retryable":true,"remediation":{"action":"Correct the listed arguments and retry."},"details":{"operation":"procedure_address","issues":[{"path":[],"reason":"invalid_value","message":"No procedure exists at the requested address: 0x140002fb0"}]}}}
{"code":"invalid_request","category":"invalid_input","message":"Analysis input is invalid. Check the arguments and try again.","retryable":true,"remediation":{"action":"Correct the listed arguments and retry."},"details":{"operation":"procedure_pseudo_code","issues":[{"path":[],"reason":"invalid_value","message":"No procedure exists at the requested address: 0x140002fb0"}]}}
//==== 0x140002fd0 {"status":"resolved","address":"0x140002fd0","name":"FUN_140002fd0"}

undefined *
FUN_140002fd0(uint *param_1,uint *param_2,uint *param_3,uint param_4,uint param_5,uint param_6)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  char *pcVar9;
  int iVar10;
  int *piVar11;
  uint uVar12;
  undefined *puVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  float fVar17;
  float fVar18;
  undefined1 auStack_d8 [32];
  uint local_b8;
  uint local_b0;
  uint *local_a0;
  char local_98 [80];
  ulonglong local_48;
  
  local_48 = DAT_14001c000 ^ (ulonglong)auStack_d8;
  uVar6 = *param_1;
  if (param_6 - 0x200 < 3) {
    puVar13 = &DAT_14001c079;
    if ((int)uVar6 < 1) goto LAB_140003583;
    piVar11 = (int *)(*(longlong *)(param_1 + 4) + 8);
    uVar14 = 0;
    uVar7 = 0xffffffff;
    iVar3 = 0;
    do {
      iVar10 = (int)(piVar11[-2] * *param_3) / *piVar11 - param_4;
      iVar4 = (int)(piVar11[-1] * *param_3) / *piVar11 - param_5;
      iVar4 = iVar4 * iVar4 + iVar10 * iVar10;
      uVar5 = (uint)uVar14;
      if (iVar3 <= iVar4 && uVar7 != 0xffffffff) {
        uVar5 = uVar7;
        iVar4 = iVar3;
      }
      iVar3 = iVar4;
      uVar7 = uVar5;
      uVar14 = uVar14 + 1;
      piVar11 = piVar11 + 3;
    } while (uVar6 != uVar14);
    if (0x90 < iVar3) {
LAB_140003348:
      puVar13 = &DAT_14001c079;
      goto LAB_140003583;
    }
    puVar13 = &DAT_14001c079;
    if ((int)uVar7 < 0) goto LAB_140003583;
    param_2[7] = 0;
    *param_2 = uVar7;
    param_2[1] = 0xffffffff;
    if ((char)param_2[8] == '\0') {
      param_2[2] = param_4;
      param_2[3] = param_5;
      param_2[4] = *param_3;
    }
    else {
      uVar6 = *param_1;
      iVar3 = uVar6 - 1;
      uVar7 = *param_3;
      uVar5 = param_1[2];
      param_2[2] = (((int)(param_4 * iVar3) / (int)(uVar7 * param_1[1])) * 2 + 1) * param_1[1];
      param_2[3] = (((int)(param_5 * iVar3) / (int)(uVar7 * uVar5)) * 2 + 1) * param_1[2];
      param_2[4] = uVar6 * 2 - 2;
    }
    goto LAB_14000357c;
  }
  if (param_6 - 0x203 < 3) {
    puVar13 = &DAT_14001c079;
    if (((int)*param_2 < 0) || (param_2[7] != 0)) goto LAB_140003583;
    if ((char)param_2[8] == '\0') {
      param_2[2] = param_4;
      param_2[3] = param_5;
LAB_140003576:
      uVar6 = *param_3;
    }
    else {
      iVar3 = (int)(param_5 * (uVar6 - 1)) / (int)(*param_3 * param_1[2]);
      uVar7 = (((int)(param_4 * (uVar6 - 1)) / (int)(*param_3 * param_1[1])) * 2 + 1) * param_1[1];
LAB_14000355a:
      param_2[2] = uVar7;
      param_2[3] = (iVar3 * 2 + 1) * param_1[2];
      uVar6 = uVar6 * 2 - 2;
    }
    param_2[4] = uVar6;
  }
  else {
    if (param_6 - 0x206 < 3) {
      uVar6 = *param_2;
      if ((int)uVar6 < 0) {
        if (uVar6 == 0xffffffff) goto LAB_140003348;
      }
      else if (param_2[7] == 0) {
        param_2[0] = 0xffffffff;
        param_2[1] = 0xffffffff;
        uVar7 = param_2[2];
        puVar13 = &DAT_14001c078;
        if (((((int)uVar7 < 0) || (uVar5 = param_2[4], (int)(param_1[1] * uVar5) <= (int)uVar7)) ||
            (uVar12 = param_2[3], (int)uVar12 < 0)) || ((int)(param_1[2] * uVar5) <= (int)uVar12))
        goto LAB_140003583;
LAB_1400032cd:
        local_b0 = uVar5;
        local_b8 = uVar12;
        uVar15 = (ulonglong)uVar7;
        uVar14 = (ulonglong)uVar6;
        pcVar9 = "P%d:%ld,%ld/%ld";
        FUN_140001000(local_98,"P%d:%ld,%ld/%ld",uVar14,uVar15);
        *(undefined1 *)(param_2 + 5) = 1;
        puVar13 = (undefined *)FUN_140004b20(local_98,pcVar9,uVar14,uVar15);
        goto LAB_140003583;
      }
      _wassert(L"ui->dragpoint == -1",L"/puzzles/untangle.c",0x592);
      puVar13 = &DAT_14001c079;
      goto LAB_140003583;
    }
    uVar7 = param_6 - 0x209;
    if (uVar7 < 4) {
      if (-1 < (int)*param_2) {
        uVar5 = *param_3;
        iVar3 = 0;
        if (uVar7 < 4) {
          iVar4 = (int)uVar5 / 2;
          switch(uVar7) {
          case 0:
            iVar4 = -iVar4;
          case 1:
            iVar3 = 0;
            break;
          case 2:
            iVar4 = -iVar4;
          case 3:
            iVar3 = iVar4;
            goto LAB_140003503;
          }
        }
        else {
LAB_140003503:
          iVar4 = 0;
        }
        uVar12 = (int)(param_2[3] * uVar5) / (int)param_2[4] + iVar4;
        uVar7 = (int)(param_2[2] * uVar5) / (int)param_2[4] + iVar3;
        if ((char)param_2[8] == '\0') {
          param_2[2] = uVar7;
          param_2[3] = uVar12;
          goto LAB_140003576;
        }
        iVar3 = (int)(uVar12 * (uVar6 - 1)) / (int)(uVar5 * param_1[2]);
        uVar7 = (((int)(uVar7 * (uVar6 - 1)) / (int)(param_1[1] * uVar5)) * 2 + 1) * param_1[1];
        goto LAB_14000355a;
      }
      uVar5 = param_2[1];
      if ((int)uVar5 < 0) {
        param_2[1] = 0;
        uVar5 = 0;
      }
      puVar13 = &DAT_14001c07a;
      if ((int)uVar6 < 1) goto LAB_140003583;
      lVar1 = *(longlong *)(param_1 + 4);
      uVar16 = (ulonglong)uVar5;
      iVar3 = *(int *)(lVar1 + 8 + uVar16 * 0xc);
      piVar11 = (int *)(lVar1 + 8);
      fVar17 = 0.0;
      uVar15 = 0xffffffff;
      uVar14 = 0;
      do {
        if (uVar16 != uVar14) {
          iVar4 = *piVar11;
          iVar8 = piVar11[-2] * iVar3 - iVar4 * *(int *)(lVar1 + uVar16 * 0xc);
          iVar10 = piVar11[-1] * iVar3 - iVar4 * *(int *)(lVar1 + 4 + uVar16 * 0xc);
          if (iVar8 != 0 || iVar10 != 0) {
            switch(uVar7) {
            case 0:
              iVar2 = iVar8;
              if (iVar10 <= -iVar8) {
joined_r0x00014000342f:
                if (iVar10 <= iVar2) {
LAB_14000343f:
                  fVar18 = (float)(int)((uint)(iVar10 * iVar10 + iVar8 * iVar8) /
                                       (uint)(iVar4 * iVar3 * iVar4 * iVar3));
                  if (fVar18 < fVar17 || (int)uVar15 == -1) {
                    uVar15 = uVar14 & 0xffffffff;
                    fVar17 = fVar18;
                  }
                }
              }
              break;
            case 1:
              iVar2 = iVar8;
              if (-iVar8 <= iVar10) {
joined_r0x00014000343d:
                if (iVar2 <= iVar10) goto LAB_14000343f;
              }
              break;
            case 2:
              if (iVar8 <= iVar10) {
                iVar2 = -iVar8;
                goto joined_r0x00014000342f;
              }
              break;
            case 3:
              if (iVar10 <= iVar8) {
                iVar2 = -iVar8;
                goto joined_r0x00014000343d;
              }
            }
          }
        }
        uVar14 = uVar14 + 1;
        piVar11 = piVar11 + 3;
      } while (uVar6 != uVar14);
      puVar13 = &DAT_14001c07a;
      local_a0 = param_2;
      if ((int)(uint)uVar15 < 0) goto LAB_140003583;
      param_2[1] = (uint)uVar15;
    }
    else {
      if (param_6 == 0x20d) {
        uVar6 = *param_2;
        if (-1 < (int)uVar6) {
          param_2[1] = uVar6;
          *param_2 = 0xffffffff;
          uVar7 = param_2[2];
          puVar13 = &DAT_14001c078;
          if ((((int)uVar7 < 0) || (uVar5 = param_2[4], (int)(param_1[1] * uVar5) <= (int)uVar7)) ||
             ((uVar12 = param_2[3], (int)uVar12 < 0 || ((int)(param_1[2] * uVar5) <= (int)uVar12))))
          goto LAB_140003583;
          goto LAB_1400032cd;
        }
        uVar6 = param_2[1];
        if (-1 < (int)uVar6) {
          param_2[7] = 0;
          *param_2 = uVar6;
          param_2[1] = 0xffffffff;
          lVar1 = (ulonglong)uVar6 * 0xc;
          param_2[2] = (int)(*param_3 * *(int *)(*(longlong *)(param_1 + 4) + lVar1)) /
                       *(int *)(*(longlong *)(param_1 + 4) + 8 + lVar1);
          param_2[3] = (int)(*param_3 * *(int *)(*(longlong *)(param_1 + 4) + 4 + lVar1)) /
                       *(int *)(*(longlong *)(param_1 + 4) + 8 + lVar1);
          goto LAB_140003576;
        }
      }
      else {
        if (((param_6 & 0xffff87ff) != 0x20e) && ((param_6 & 0xffff87ff) != 9)) {
          puVar13 = &DAT_14001c07a;
          goto LAB_140003583;
        }
        if (-1 < (int)*param_2) goto LAB_140003348;
        if (-1 < (int)param_2[1]) {
          param_2[1] = (int)((-(uint)((param_6 & 0x2000) != 0) | 1) + uVar6 + param_2[1]) %
                       (int)uVar6;
          goto LAB_14000357c;
        }
      }
      param_2[1] = 0;
    }
  }
LAB_14000357c:
  puVar13 = &DAT_14001c078;
LAB_140003583:
  FUN_140016090(local_48 ^ (ulonglong)auStack_d8);
  return puVar13;
}


//==== 0x140003600 {"status":"resolved","address":"0x140003600","name":"FUN_140003600"}

int * FUN_140003600(int *param_1,char *param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  void *pvVar7;
  char *pcVar8;
  void *pvVar9;
  size_t _Size;
  undefined1 auStack_98 [32];
  undefined4 *local_78;
  int *local_70;
  int *local_68;
  int local_5c;
  undefined4 local_58;
  undefined4 local_54;
  int local_50;
  uint local_4c;
  ulonglong local_48;
  
  local_48 = DAT_14001c000 ^ (ulonglong)auStack_98;
  iVar3 = *param_1;
  pcVar8 = param_2;
  piVar6 = FUN_140004a60(0x30,param_2,param_3,param_4);
  *piVar6 = *param_1;
  piVar6[1] = param_1[1];
  piVar6[2] = param_1[2];
  _Size = (longlong)iVar3 * 0xc;
  pvVar7 = FUN_140004a60(_Size,pcVar8,param_3,param_4);
  *(void **)(piVar6 + 4) = pvVar7;
  pvVar9 = *(void **)(param_1 + 4);
  memcpy(pvVar7,pvVar9,_Size);
  piVar4 = *(int **)(param_1 + 6);
  *(int **)(piVar6 + 6) = piVar4;
  *piVar4 = *piVar4 + 1;
  *(char *)(piVar6 + 10) = (char)param_1[10];
  *(undefined1 *)((longlong)piVar6 + 0x29) = *(undefined1 *)((longlong)param_1 + 0x29);
  *(undefined1 *)((longlong)piVar6 + 0x2a) = *(undefined1 *)((longlong)param_1 + 0x2a);
  iVar5 = FUN_140005780(*(longlong **)(*(longlong *)(piVar6 + 6) + 8));
  pvVar7 = FUN_140004a60((longlong)iVar5 << 2,pvVar9,_Size,param_4);
  *(void **)(piVar6 + 8) = pvVar7;
  pvVar9 = *(void **)(param_1 + 8);
  iVar5 = FUN_140005780(*(longlong **)(*(longlong *)(piVar6 + 6) + 8));
  memcpy(pvVar7,pvVar9,(longlong)iVar5 << 2);
  *(undefined1 *)((longlong)piVar6 + 0x2a) = 0;
  while( true ) {
    cVar1 = *param_2;
    if (cVar1 == 'S') {
      pcVar8 = param_2 + 2;
      cVar2 = param_2[1];
      *(undefined2 *)((longlong)piVar6 + 0x29) = 0x101;
      cVar1 = param_2[(ulonglong)(cVar2 == ';') + 1];
      param_2 = param_2 + 1;
      if (cVar2 == ';') {
        param_2 = pcVar8;
      }
    }
    else if (cVar1 == '\0') {
      FUN_1400044f0((longlong)piVar6);
      goto LAB_1400037da;
    }
    if (cVar1 != 'P') break;
    local_68 = &local_50;
    local_78 = &local_58;
    local_70 = &local_5c;
    iVar5 = FUN_1400046d0(param_2 + 1,"%d:%ld,%ld/%ld%n",&local_4c,&local_54);
    if ((((iVar5 != 4) || ((int)local_4c < 0)) || (iVar3 <= (int)local_4c)) || (local_5c < 1))
    break;
    *(undefined4 *)(*(longlong *)(piVar6 + 4) + (ulonglong)local_4c * 0xc) = local_54;
    *(undefined4 *)(*(longlong *)(piVar6 + 4) + 4 + (longlong)(int)local_4c * 0xc) = local_58;
    *(int *)(*(longlong *)(piVar6 + 4) + 8 + (longlong)(int)local_4c * 0xc) = local_5c;
    param_2 = param_2 + (ulonglong)(param_2[(longlong)local_50 + 1] == ';') + (longlong)local_50 + 1
    ;
  }
  FUN_1400028a0(piVar6);
  piVar6 = (int *)0x0;
LAB_1400037da:
  FUN_140016090(local_48 ^ (ulonglong)auStack_98);
  return piVar6;
}


//==== 0x140003810 {"status":"resolved","address":"0x140003810","name":"FUN_140003810"}

void FUN_140003810(int *param_1,int param_2,undefined8 param_3,int *param_4,int *param_5)

{
  int iVar1;
  
  iVar1 = FUN_140003f30(*param_1 * 3);
  *param_5 = iVar1 * param_2;
  *param_4 = iVar1 * param_2;
  return;
}


//==== 0x140003840 {"status":"unknown","error":{"code":"invalid_request","category":"invalid_input","message":"Analysis input is invalid. Check the arguments and try again.","retryable":true,"remediation":{"action":"Correct the listed arguments and retry."},"details":{"operation":"procedure_address","issues":[{"path":[],"reason":"invalid_value","message":"No procedure exists at the requested address: 0x140003840"}]}}}
{"code":"invalid_request","category":"invalid_input","message":"Analysis input is invalid. Check the arguments and try again.","retryable":true,"remediation":{"action":"Correct the listed arguments and retry."},"details":{"operation":"procedure_pseudo_code","issues":[{"path":[],"reason":"invalid_value","message":"No procedure exists at the requested address: 0x140003840"}]}}
//==== 0x140003850 {"status":"resolved","address":"0x140003850","name":"FUN_140003850"}

void * FUN_140003850(undefined8 param_1,undefined4 *param_2,undefined8 param_3,undefined8 param_4)

{
  void *pvVar1;
  
  pvVar1 = FUN_140004a60(0x84,param_2,param_3,param_4);
  FUN_1400053f0(param_1,(longlong)pvVar1,1,-1,0);
  *(undefined8 *)((longlong)pvVar1 + 0x18) = 0;
  *(undefined8 *)((longlong)pvVar1 + 0x20) = 0x3f80000000000000;
  *(undefined8 *)((longlong)pvVar1 + 0x28) = 0;
  *(undefined8 *)((longlong)pvVar1 + 0x30) = 0;
  *(undefined8 *)((longlong)pvVar1 + 0x34) = 0;
  *(undefined8 *)((longlong)pvVar1 + 0x3c) = 0;
  *(undefined8 *)((longlong)pvVar1 + 0x44) = 0x3f8000003f800000;
  *(undefined8 *)((longlong)pvVar1 + 0x4c) = 0x3f8000003f800000;
  *(undefined8 *)((longlong)pvVar1 + 0x54) = 0x3f0000003f000000;
  *(undefined8 *)((longlong)pvVar1 + 0x5c) = 0x3f8000003f000000;
  *(undefined8 *)((longlong)pvVar1 + 100) = 0;
  *(undefined8 *)((longlong)pvVar1 + 0x6c) = 0x3f0000003f000000;
  *(undefined8 *)((longlong)pvVar1 + 0x74) = 0x3f8000003f000000;
  *(undefined8 *)((longlong)pvVar1 + 0x7c) = 0x3f8000003f800000;
  *param_2 = 0xb;
  return pvVar1;
}


//==== 0x1400038e0 {"status":"resolved","address":"0x1400038e0","name":"FUN_1400038e0"}

undefined4 * FUN_1400038e0(undefined8 param_1,int *param_2,undefined8 param_3,undefined8 param_4)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 *puVar3;
  longlong lVar4;
  int *piVar5;
  
  piVar5 = param_2;
  puVar1 = FUN_140004a60(0x20,param_2,param_3,param_4);
  *puVar1 = 0;
  pvVar2 = FUN_140004a60((longlong)*param_2 << 2,piVar5,param_3,param_4);
  *(void **)(puVar1 + 4) = pvVar2;
  puVar3 = FUN_140004a60((longlong)*param_2 << 2,piVar5,param_3,param_4);
  *(undefined4 **)(puVar1 + 6) = puVar3;
  if (0 < *param_2) {
    *puVar3 = 0xffffffff;
    **(undefined4 **)(puVar1 + 4) = 0xffffffff;
    if (1 < *param_2) {
      lVar4 = 1;
      do {
        *(undefined4 *)(*(longlong *)(puVar1 + 6) + lVar4 * 4) = 0xffffffff;
        *(undefined4 *)(*(longlong *)(puVar1 + 4) + lVar4 * 4) = 0xffffffff;
        lVar4 = lVar4 + 1;
      } while (lVar4 < *param_2);
    }
  }
  *(undefined8 *)(puVar1 + 1) = 0xffffffffffffffff;
  puVar1[3] = 0xffffffff;
  return puVar1;
}


//==== 0x140003980 {"status":"resolved","address":"0x140003980","name":"FUN_140003980"}

void FUN_140003980(undefined8 param_1,void *param_2)

{
  FUN_140004aa0(*(void **)((longlong)param_2 + 0x18));
  FUN_140004aa0(*(void **)((longlong)param_2 + 0x10));
  FUN_140004aa0(param_2);
  return;
}


//==== 0x1400039b0 {"status":"resolved","address":"0x1400039b0","name":"FUN_1400039b0"}

void FUN_1400039b0(longlong *param_1,int *param_2,uint *param_3,uint *param_4,undefined8 param_5,
                  uint *param_6,float param_7,float param_8)

{
  ulonglong uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  ulonglong uVar8;
  longlong lVar9;
  ulonglong uVar10;
  bool bVar11;
  undefined8 uVar12;
  longlong lVar13;
  undefined1 auStack_108 [32];
  int local_e8;
  int local_e0;
  int local_d8;
  uint *local_d0;
  int local_c0;
  int local_bc;
  uint local_b8;
  uint local_b4;
  ulonglong local_60;
  
  local_60 = DAT_14001c000 ^ (ulonglong)auStack_108;
  local_c0 = 1;
  if ((param_8 != 0.0) || (NAN(param_8))) {
    local_c0 = ((int)((param_8 * 4.0) / 0.3) & 1U) + 9;
  }
  iVar3 = local_c0;
  if ((int)*param_4 < 1) {
    bVar11 = false;
  }
  else {
    lVar13 = 2;
    uVar8 = 0;
    bVar11 = false;
    do {
      uVar10 = *(ulonglong *)(*(longlong *)(param_4 + 4) + -8 + lVar13 * 4);
      uVar6 = *(uint *)(*(longlong *)(param_4 + 4) + lVar13 * 4);
      if ((uVar8 == *param_6) && (param_6[7] == 0)) {
        uVar10 = *(ulonglong *)(param_6 + 2);
        uVar6 = param_6[4];
      }
      uVar4 = uVar6;
      if (param_3 != (uint *)0x0) {
        uVar1 = *(ulonglong *)(*(longlong *)(param_3 + 4) + -8 + lVar13 * 4);
        uVar2 = *(uint *)(*(longlong *)(param_3 + 4) + lVar13 * 4);
        uVar4 = uVar2 * uVar6;
        iVar5 = (int)((uVar1 & 0xffffffff) * (ulonglong)uVar6);
        iVar7 = (int)((uVar1 >> 0x20) * (ulonglong)uVar6);
        uVar10 = CONCAT44((int)((param_7 / (float)param_6[6]) *
                                (float)((int)((uVar10 >> 0x20) * (ulonglong)uVar2) - iVar7) +
                               (float)iVar7),
                          (int)((param_7 / (float)param_6[6]) *
                                (float)((int)((ulonglong)uVar2 * (uVar10 & 0xffffffff)) - iVar5) +
                               (float)iVar5));
      }
      iVar7 = ((int)uVar10 * *param_2) / (int)uVar4;
      iVar5 = ((int)(uVar10 >> 0x20) * *param_2) / (int)uVar4;
      if ((*(int *)(*(longlong *)(param_2 + 4) + uVar8 * 4) != iVar7) ||
         (*(int *)(*(longlong *)(param_2 + 6) + uVar8 * 4) != iVar5)) {
        bVar11 = true;
      }
      *(int *)(*(longlong *)(param_2 + 4) + uVar8 * 4) = iVar7;
      *(int *)(*(longlong *)(param_2 + 6) + uVar8 * 4) = iVar5;
      uVar8 = uVar8 + 1;
      lVar13 = lVar13 + 3;
    } while ((longlong)uVar8 < (longlong)(int)*param_4);
  }
  if (param_2[1] == local_c0) {
    uVar4 = param_2[2];
    uVar6 = *param_6;
    if (((uVar4 == *param_6) && (uVar6 = uVar4, param_2[3] == param_6[1])) && (!bVar11))
    goto LAB_140003dde;
  }
  else {
    uVar6 = *param_6;
  }
  param_2[2] = uVar6;
  param_2[3] = param_6[1];
  param_2[1] = local_c0;
  iVar5 = *param_2;
  local_e8 = FUN_140003f30(*param_4 * 3);
  local_e8 = local_e8 * iVar5;
  local_e0 = iVar3;
  local_bc = local_e8;
  FUN_140004810(param_1);
  lVar13 = FUN_1400059b0(*(longlong **)(*(longlong *)(param_4 + 6) + 8),0);
  if (lVar13 != 0) {
    if (param_3 == (uint *)0x0) {
      param_3 = param_4;
    }
    lVar9 = 0;
    do {
      if (*(char *)((longlong)param_6 + 0x21) == '\0') {
        local_e0 = 2;
      }
      else {
        local_e0 = 3 - (uint)(*(int *)(*(longlong *)(param_3 + 8) + lVar9 * 4) == 0);
      }
      local_e8 = *(int *)(*(longlong *)(param_2 + 6) + (longlong)*(int *)(lVar13 + 4) * 4);
      FUN_140004820(param_1);
      lVar9 = lVar9 + 1;
      lVar13 = FUN_1400059b0(*(longlong **)(*(longlong *)(param_4 + 6) + 8),(int)lVar9);
    } while (lVar13 != 0);
  }
  uVar8 = (ulonglong)*param_4;
  lVar13 = 0;
  do {
    if (0 < (int)uVar8) {
      iVar3 = (&DAT_1400171b0)[lVar13];
      uVar10 = 0;
      do {
        uVar6 = *param_6;
        uVar8 = (ulonglong)uVar6;
        iVar5 = 6;
        if ((uVar10 != uVar8) && (iVar5 = 7, uVar10 != param_6[1])) {
          if (-1 < (int)uVar6) {
            local_b8 = (uint)uVar10;
            if (uVar10 >= uVar8 && uVar10 != uVar8) {
              local_b8 = uVar6;
            }
            local_b4 = (uint)uVar10;
            if (uVar10 < uVar8) {
              local_b4 = uVar6;
            }
            lVar9 = FUN_140005d50(*(longlong **)(*(longlong *)(param_4 + 6) + 8),(longlong)&local_b8
                                  ,(undefined *)0x0);
            iVar5 = 8;
            if (lVar9 != 0) goto LAB_140003d40;
          }
          iVar5 = 5;
        }
LAB_140003d40:
        if (iVar5 == iVar3) {
          if (*(char *)((longlong)param_6 + 0x22) == '\0') {
            local_e0 = 4;
            local_e8 = iVar3;
            FUN_140004830(param_1);
          }
          else {
            local_e0 = local_c0;
            local_e8 = local_c0;
            uVar12 = 0xc;
            FUN_140004830(param_1);
            FUN_140001000(&local_b8,&DAT_1400182a8,uVar10 & 0xffffffff,uVar12);
            local_e0 = 0x101;
            local_e8 = 0x12;
            local_d8 = iVar3;
            local_d0 = &local_b8;
            FUN_140004800(param_1);
          }
        }
        uVar10 = uVar10 + 1;
        uVar8 = (ulonglong)(int)*param_4;
      } while ((longlong)uVar10 < (longlong)uVar8);
    }
    lVar13 = lVar13 + 1;
  } while (lVar13 != 4);
  local_e8 = local_bc;
  FUN_140004840(param_1);
LAB_140003dde:
  FUN_140016090(local_60 ^ (ulonglong)auStack_108);
  return;
}


//==== 0x140003e20 {"status":"unknown","error":{"code":"invalid_request","category":"invalid_input","message":"Analysis input is invalid. Check the arguments and try again.","retryable":true,"remediation":{"action":"Correct the listed arguments and retry."},"details":{"operation":"procedure_address","issues":[{"path":[],"reason":"invalid_value","message":"No procedure exists at the requested address: 0x140003e20"}]}}}
{"code":"invalid_request","category":"invalid_input","message":"Analysis input is invalid. Check the arguments and try again.","retryable":true,"remediation":{"action":"Correct the listed arguments and retry."},"details":{"operation":"procedure_pseudo_code","issues":[{"path":[],"reason":"invalid_value","message":"No procedure exists at the requested address: 0x140003e20"}]}}
//==== 0x140003e50 {"status":"unknown","error":{"code":"invalid_request","category":"invalid_input","message":"Analysis input is invalid. Check the arguments and try again.","retryable":true,"remediation":{"action":"Correct the listed arguments and retry."},"details":{"operation":"procedure_address","issues":[{"path":[],"reason":"invalid_value","message":"No procedure exists at the requested address: 0x140003e50"}]}}}
{"code":"invalid_request","category":"invalid_input","message":"Analysis input is invalid. Check the arguments and try again.","retryable":true,"remediation":{"action":"Correct the listed arguments and retry."},"details":{"operation":"procedure_pseudo_code","issues":[{"path":[],"reason":"invalid_value","message":"No procedure exists at the requested address: 0x140003e50"}]}}
//==== 0x140003e80 {"status":"resolved","address":"0x140003e80","name":"FUN_140003e80"}

void FUN_140003e80(int *param_1,int *param_2,longlong param_3,undefined8 param_4,int *param_5,
                  int *param_6,undefined4 *param_7,undefined4 *param_8)

{
  int iVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  ulonglong uVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  
  if ((*param_1 < 0) || (param_1[7] != 0)) {
    uVar5 = (ulonglong)(uint)param_1[1];
    if (param_1[1] < 0) {
      return;
    }
    lVar4 = *(longlong *)(param_3 + 0x10);
    piVar7 = (int *)(lVar4 + uVar5 * 0xc);
    piVar8 = (int *)(lVar4 + uVar5 * 0xc + 4);
    piVar6 = (int *)(lVar4 + uVar5 * 0xc + 8);
  }
  else {
    piVar7 = param_1 + 2;
    piVar8 = param_1 + 3;
    piVar6 = param_1 + 4;
  }
  iVar1 = *piVar6;
  iVar2 = *param_2;
  iVar3 = *piVar8;
  *param_5 = (*piVar7 * iVar2) / iVar1 + -6;
  *param_6 = (iVar2 * iVar3) / iVar1 + -6;
  *param_8 = 0xd;
  *param_7 = 0xd;
  return;
}


//==== 0x140003f10 {"status":"unknown","error":{"code":"invalid_request","category":"invalid_input","message":"Analysis input is invalid. Check the arguments and try again.","retryable":true,"remediation":{"action":"Correct the listed arguments and retry."},"details":{"operation":"procedure_address","issues":[{"path":[],"reason":"invalid_value","message":"No procedure exists at the requested address: 0x140003f10"}]}}}
{"code":"invalid_request","category":"invalid_input","message":"Analysis input is invalid. Check the arguments and try again.","retryable":true,"remediation":{"action":"Correct the listed arguments and retry."},"details":{"operation":"procedure_pseudo_code","issues":[{"path":[],"reason":"invalid_value","message":"No procedure exists at the requested address: 0x140003f10"}]}}