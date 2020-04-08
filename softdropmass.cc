typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > LorentzVector;

int softdropmass(){
        vector<float> *m=0;
        float scale;

	TChain *www=new TChain("t_ss");
	www->Add("/home/yulunmiao/Documents/CMS_data/WWWto2lFatJet/data/2018/www/*");
	www->SetBranchAddress("evt_scale1fb",&scale);
	www->SetBranchAddress("ak8jets_softdropMass",&m);

	TChain *ww=new TChain("t_ss");
        ww->Add("/home/yulunmiao/Documents/CMS_data/WWWto2lFatJet/data/2018/ww/*");
        ww->SetBranchAddress("evt_scale1fb",&scale);
        ww->SetBranchAddress("ak8jets_softdropMass",&m);

       	TChain *zz=new TChain("t_ss");
        zz->Add("/home/yulunmiao/Documents/CMS_data/WWWto2lFatJet/data/2018/zz/*");
        zz->SetBranchAddress("evt_scale1fb",&scale);
        zz->SetBranchAddress("ak8jets_softdropMass",&m);

	TChain *wz=new TChain("t_ss");
        wz->Add("/home/yulunmiao/Documents/CMS_data/WWWto2lFatJet/data/2018/zz/*");
        wz->SetBranchAddress("evt_scale1fb",&scale);
        wz->SetBranchAddress("ak8jets_softdropMass",&m);

	TChain *ttz=new TChain("t_ss");
        ttz->Add("/home/yulunmiao/Documents/CMS_data/WWWto2lFatJet/data/2018/ttz/*");
        ttz->SetBranchAddress("evt_scale1fb",&scale);
        ttz->SetBranchAddress("ak8jets_softdropMass",&m);
   
	TChain *ttw=new TChain("t_ss");
        ttw->Add("/home/yulunmiao/Documents/CMS_data/WWWto2lFatJet/data/2018/ttw/*");
        ttw->SetBranchAddress("evt_scale1fb",&scale);
        ttw->SetBranchAddress("ak8jets_softdropMass",&m);

	TChain *ttbar=new TChain("t_ss");
        ttbar->Add("/home/yulunmiao/Documents/CMS_data/WWWto2lFatJet/data/2018/ttbar/*");
        ttbar->SetBranchAddress("evt_scale1fb",&scale);
        ttbar->SetBranchAddress("ak8jets_softdropMass",&m);

        TChain *dy=new TChain("t_ss");
        dy->Add("/home/yulunmiao/Documents/CMS_data/WWWto2lFatJet/data/2018/dy/*");
        dy->SetBranchAddress("evt_scale1fb",&scale);
        dy->SetBranchAddress("ak8jets_softdropMass",&m);

        TChain *wjets=new TChain("t_ss");
        wjets->Add("/home/yulunmiao/Documents/CMS_data/WWWto2lFatJet/data/2018/wjets/*");
        wjets->SetBranchAddress("evt_scale1fb",&scale);
        wjets->SetBranchAddress("ak8jets_softdropMass",&m);

	TH1F *hwww=new TH1F("","",70,10,150);
        TH1F *hww=new TH1F("","",70,10,150);
	TH1F *hzz=new TH1F("","",70,10,150);
        TH1F *hwz=new TH1F("","",70,10,150);
        TH1F *httz=new TH1F("","",70,10,150);
        TH1F *httw=new TH1F("","",70,10,150);
	TH1F *httbar=new TH1F("","",70,10,150);
	TH1F *hdy=new TH1F("","",70,10,150);
	TH1F *hwjets=new TH1F("","",70,10,150);

	for(int i=0;i<www->GetEntries();i++){
		www->GetEntry(i);
		if(m->size()!=1) continue;
		hwww->Fill(m->at(0),50*scale*136.9);
	}

	for(int i=0;i<ww->GetEntries();i++){
                ww->GetEntry(i);
                if(m->size()!=1) continue;
                hww->Fill(m->at(0),scale*136.9);
        }
        for(int i=0;i<zz->GetEntries();i++){
                zz->GetEntry(i);
                if(m->size()!=1) continue;
                hzz->Fill(m->at(0),scale*136.9);
        }
        for(int i=0;i<wz->GetEntries();i++){
                wz->GetEntry(i);
                if(m->size()!=1) continue;
                hwz->Fill(m->at(0),scale*136.9);
        }
        for(int i=0;i<ttz->GetEntries();i++){
                ttz->GetEntry(i);
                if(m->size()!=1) continue;
                httz->Fill(m->at(0),scale*136.9);
        }
        for(int i=0;i<ttw->GetEntries();i++){
                ttw->GetEntry(i);
                if(m->size()!=1) continue;
                httw->Fill(m->at(0),scale*136.9);
        }
        for(int i=0;i<ttbar->GetEntries();i++){
                ttbar->GetEntry(i);
                if(m->size()!=1) continue;
                httbar->Fill(m->at(0),scale*136.9);
        }
        for(int i=0;i<dy->GetEntries();i++){
                dy->GetEntry(i);
                if(m->size()!=1) continue;
                hdy->Fill(m->at(0),scale*136.9);
        }
        for(int i=0;i<wjets->GetEntries();i++){
                wjets->GetEntry(i);
                if(m->size()!=1) continue;
                hwjets->Fill(m->at(0),scale*136.9);
        }

	hww->SetFillColor(kRed);
	hzz->SetFillColor(kPink);
	hwz->SetFillColor(kOrange);
	httz->SetFillColor(kGreen);
	httw->SetFillColor(kBlue);
	httbar->SetFillColor(kYellow);
	hdy->SetFillColor(kGray);
	hwjets->SetFillColor(kCyan);

	THStack *hsbkg=new THStack("","");

	hsbkg->Add(hww);
	hsbkg->Add(hzz);
        hsbkg->Add(hwz);
        hsbkg->Add(httz);
        hsbkg->Add(httw);
        hsbkg->Add(httbar);
        hsbkg->Add(hdy);
        hsbkg->Add(hwjets);

	TLegend *l=new TLegend(0.15,0.6,0.35,0.85);
	l->AddEntry(hwww,"signalx50");
	l->AddEntry(hww,"hww");
	l->AddEntry(hzz,"hzz");
	l->AddEntry(hwz,"hwz");
	l->AddEntry(httz,"httz");
	l->AddEntry(httw,"httw");
	l->AddEntry(httbar,"httbar");
	l->AddEntry(hdy,"hdy");
	l->AddEntry(hwjets,"hwjets");

	TCanvas *c1=new TCanvas("c1","c1",1920,1080);
	hwww->Draw("hist");
	hsbkg->Draw("hist same");
	
	l->Draw();

	return 0;
}
